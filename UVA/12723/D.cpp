#include <cstdio>
#include <algorithm>
const int N = 500 + 10;

int n, K;
double p[N], a[N];
double f[N];

double solve()
{
	for(int i = 1; i <= n; i++)
	{
		f[i] = a[i];
		for(int k = 1; k <= K && i - k >= 0; k++)
			f[i] += p[k] * f[i-k];
	}
	return f[n];
}

int main()
{
	freopen("D.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &K);
		for(int i = 1; i <= K; i++) scanf("%lf", &p[i]);
		//for(int i = 1; i <= n; i++)
		for(int i = n; i >= 1; i--)
		{
			a[i] = 0;
			int q; scanf("%d", &q);
			while(q--)
			{
				double x, y;scanf("%lf%lf", &x, &y);
				a[i] += x * y;
			}
		}
		printf("Case #%d: %.6lf\n", cas, solve());
	}
	return 0;
}
