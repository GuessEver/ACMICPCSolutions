#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;

const int N = 1000 + 10;

int n, K, L;
int f[N][20*N];
int F[N], D[N];

int main()
{
	while(scanf("%d%d%d", &n, &K, &L) == 3 && (n || K || L))
	{
		int maxf = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &F[i], &D[i]);
			maxf += F[i];
		}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= maxf;j++)
				f[i][j] = 0x3f3f3f3f;
		f[0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j <= maxf; j++)
			{
				f[i][j] = min(f[i][j], max(0, f[i-1][j]-K));
				if(j >= F[i] && f[i-1][j-F[i]] + D[i] <= L)
					f[i][j] = min(f[i][j], f[i-1][j-F[i]] + D[i]);
			}
		int ans = 0;
		for(int j = maxf; j >= 0; j--)
			if(f[n][j] <= L)
			{
				ans = j;
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}
