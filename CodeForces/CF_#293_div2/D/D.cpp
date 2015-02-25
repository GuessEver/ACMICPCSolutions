#include <cstdio>

int n, t;
double p;
double f[2010][2010];

int main()
{
	scanf("%d%lf%d", &n, &p, &t);
	f[0][0] = 1;
	for(int i = 1; i <= t; i++)
		for(int j = 0; j <= n; j++)
		{
			if(j < n) f[i][j] = (1-p) * f[i-1][j];
			else f[i][j] = f[i-1][j];
			if(j > 0) f[i][j] += p * f[i-1][j-1];
		}
	/*for(int i = 1; i <= t; i++)
	{
		for(int j = 0; j <= n; j++) printf("%.5f ", f[i][j]);
		puts("");
	}*/
	double res = 0;
	for(int j = 0; j <= n; j++) res += j * f[t][j];
	printf("%.4f\n", res);
	return 0;
}
