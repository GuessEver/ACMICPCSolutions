#include <cstdio>
#include <algorithm>

const int N = 100 + 10;

int n, m, u[N], sum[N];
double f[N][N];

bool cmp(int a, int b) { return a > b; }

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &u[i]);
		std::sort(u+1, u+1+n, cmp);
		sum[0] = 0;
		for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + u[i];
		for(int i = 0; i <= n; i++)
			for(int t = 0; t <= m; t++)
				f[i][t] = 1e20;
		f[0][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int t = 1; t <= m; t++)
				for(int j = 0; j < i; j++)
					f[i][t] = std::min(f[i][t], f[j][t-1] + 1.0 * (sum[i] - sum[j]) / sum[n] * i);
		printf("%.4f\n", f[n][m]);
	}
	return 0;
}
