#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

int n, m, g[30][30];
int f[1<<13][510];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int fac(int a)
{
	int res = 1;
	for(int i = 1; i <= a; i++) res *= i;
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				scanf("%d", &g[i][j]);
		int tot = (1 << n);
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for(int S = 0; S < tot; S++)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(S & (1 << (i-1))) cnt++; 
					// There are cnt numbers had been done
			// now the (cnt+1)th number will be put into the jth place
			for(int j = 1; j <= n; j++)
			{
				// The jth place mustn't have been put
				if(S & (1 << (j-1))) continue;
				for(int cost = 0; cost <= m; cost++)
				{
					int now = cost + g[cnt+1][j];
					if(now > m) now = m;
					f[S | (1 << (j-1))][now] += f[S][cost];
				}
			}
		}
		// Use Math method, we can get the answer that
		// P = (1 - p^n) / (1 - p) - n * p^n 
		// And p = methods that cannot be passed / total methods
		// n -> +oo     So  :   P -> 1 / (1 - p)
		// So   P = total methods / methods that can be passed
		int A = f[tot-1][m], B = fac(n);
		if(A)
		{
			int d = gcd(A, B);
			printf("%d/%d\n", B/d, A/d);
		}
		else printf("No solution\n");
	}
	return 0;
}
