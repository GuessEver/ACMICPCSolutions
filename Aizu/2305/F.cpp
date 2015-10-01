#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 20 + 10;
const int A = 1000000 + 10;
int n, a[N];
double dp[2][A];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 0; i <= 1; i++)
		for(int j = 1; j <= A - 10; j++) dp[i][j] = 1e20;
	dp[0][1] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= A - 10; j++) dp[(i+1)%2][j] = 1e20;
		for(int j = 1; j <= A - 10; j++)
		{
			if(fabs(dp[i%2][j] - 1e20) < 1e-10) continue;
			for(int k = 1; j * k <= A - 10; k++)
				dp[(i+1)%2][j*k] = std::min(dp[(i+1)%2][j*k], std::max(dp[i%2][j], fabs(0.0 + a[i+1] - j * k) / a[i+1]));
		}
	}

	double res = 1e20;
	for(int j = 1; j <= A - 10; j++) res = std::min(res, dp[n%2][j]);
	printf("%.12f\n", res);
	//for(int i = 1; i <= n; i++)
	//	for(int j = 1; j <= 50; j++) printf("dp[%d][%d] = %.4f\n", i, j, dp[i][j]);
	return 0;
}
