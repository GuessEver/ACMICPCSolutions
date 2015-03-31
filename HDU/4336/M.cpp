#include <cstdio>

int n, a[30], tot;
double p[30];
double f[1<<21];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		p[0] = 0.0; a[0] = 0; tot = 1 << n;
		for(int i = 1; i <= n; i++)
		{
			a[i] = (1 << (i - 1));
			scanf("%lf", &p[i]);
			p[0] += p[i];
		}
		p[0] = 1.0 - p[0];
		f[tot - 1] = 0;
		for(int S = tot - 2; S >= 0; S--)
		{
			double tmp1 = 0, tmp2 = 0;
			for(int j = 0; j <= n; j++)
			{
				if((S | a[j]) == S) tmp1 += p[j];
				else tmp2 += f[S | a[j]] * p[j];
			}
			f[S] = (tmp2 + 1.0) / (1.0 - tmp1);
		}
		printf("%.5f\n", f[0]);
	}
	return 0;
}
