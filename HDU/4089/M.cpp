#include <cstdio>
#include <cmath>
#include <algorithm>

const int N = 2000 + 10;

int n, m, k;
double p1, p2, p3, p4;

double dp[N][N];
double c[N];

int main()
{
	while(scanf("%d%d%d%lf%lf%lf%lf", &n, &m, &k, &p1, &p2, &p3, &p4) == 7)
	{
		if(fabs(1.0 - p1 - p2) < 1e-9)
		{
			puts("0.00000");
			continue;
		}
		dp[1][1] = p4 / (1.0 - p1 - p2);
		double p21 = p2 / (1.0 - p1);
		double p31 = p3 / (1.0 - p1);
		double p41 = p4 / (1.0 - p1);
		for(int i = 2; i <= n; i++)
		{
			c[1] = p41;
			for(int j = 2; j <= std::min(k, i); j++) c[j] = p31 * dp[i-1][j-1] + p41;
			for(int j = k + 1; j <= i; j++) c[j] = p31 * dp[i-1][j-1];
			double tmp = 0.0, pp = 1.0;
			for(int j = i; j >= 1; j--)
			{
				tmp += pp * c[j];
				pp *= p21;
			}
			dp[i][i] = tmp / (1 - pp);
			dp[i][1] = p21 * dp[i][i] + p41;
			for(int j = 2; j < i; j++)
				dp[i][j] = p21 * dp[i][j-1] + c[j];
		}
		printf("%.5f\n", dp[n][m]);
	}
	return 0;
}
