#include <cstdio>
#include <cstring>
#include <algorithm>
const int M = 2000 + 10;
const int N = 1000 + 10;

int n, m, w[N*2], a[N*2];
long long f[M];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for(int i = 1; i <= n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &z, &x, &y);
			w[i*2-1] = w[i*2] = z;
			a[i*2-1] = x + y;
			a[i*2] = x;
		}
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= 2 * n; i++)
		{
			if(i % 2 == 1)
			{
				for(int j = m; j >= w[i]; j--)
					f[j] = std::max(f[j], f[j-w[i]] + a[i]);
			}
			else {
				for(int j = w[i]; j <= m; j++)
					f[j] = std::max(f[j], f[j-w[i]] + a[i]);
			}
		}
		long long res = 0;
		for(int j = 0; j <= m; j++) res = std::max(res, f[j]);
		printf("%lld\n", res);
	}
	return 0;
}
