#include <cstdio>
// Attention: the champion may be more than one person!!!
int n, m, t;
double p[1010][40];
double f[1010][40][40];

int main()
{
	while(scanf("%d%d%d", &m, &t, &n) == 3 && (m || t || n))
	{
		for(int i = 1; i <= t; i++)
			for(int j = 1; j <= m; j++) scanf("%lf", &p[i][j]);
		for(int i = 1; i <= t; i++)
		{
			f[i][0][0] = 1;
			for(int j = 1; j <= m; j++)
				for(int k = 0; k <= j; k++)
				{
					f[i][j][k] = 0;
					if(k > 0) f[i][j][k] += f[i][j-1][k-1] * p[i][j];
					if(k < j) f[i][j][k] += f[i][j-1][k] * (1 - p[i][j]);
				}
		}
		/*for(int i = 1; i <= t; i++)
		{
			for(int j = 0; j <= m; j++) printf("%.3f ", f[i][m][j]);
			puts("");
		}*/
		double res1 = 1, res2 = 1;
		for(int i = 1; i <= t; i++)
		{
			res1 *= (1 - f[i][m][0]);
			double tmp = 0;
			for(int j = 1; j < n; j++) tmp += f[i][m][j];
			res2 *= tmp;
		}
		printf("%.3f\n", res1 - res2);
	}
	return 0;
}
