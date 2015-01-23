#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
using std::min;

const int N = 1000 + 10;

int n, K, L;
int f[20*N];
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
		for(int j = 0; j <= maxf;j++)
			f[j] = 0x3f3f3f3f;
		f[0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = maxf; j >= 0; j--)
			{
				f[j] = min(f[j], max(0, f[j]-K));
				if(j >= F[i] && f[j-F[i]] + D[i] <= L)
					f[j] = min(f[j], f[j-F[i]] + D[i]);
			}
		for(int j = maxf; j >= 0; j--)
			if(f[j] <= L)
			{
				printf("%d\n", j);
				break;
			}
	}
	return 0;
}
