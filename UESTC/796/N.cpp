#include <cstdio>

const int N = 50 + 10;
int n, a[N];
double dp[N][3000];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	double res = 0;
	dp[0][2047] = 1.0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= 2047; j++)
		{
			int cnt = 0;
			for(int k = 1; k <= n; k++) cnt += ((a[k] & j) == j);
			if(cnt < i) continue;
			dp[i+1][j] += (cnt - i) * (dp[i][j] / (n - i));
			for(int k = 1; k <= n; k++) if((j & a[k]) != j)
			dp[i+1][(j&a[k])] += dp[i][j] / (n - i);
		}
		res += dp[i+1][0] * (i + 1);
	}
	printf("%.3f\n", res);
	return 0;
}
