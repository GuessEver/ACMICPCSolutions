#include <cstdio>
const int N = 300 + 10;
const int mod = 1000000007;

int n, k, a[N];
int dp[N][N];

int main()
{
	freopen("monotonic.in", "r", stdin);
	freopen("monotonic.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int sum = 0;
	for(int i = 1; i <= k; i++)
	{
		int x; scanf("%d", &x);
		a[sum += x] = 1;
	}
	for(int i = 1; i <= n; i++) dp[1][i] = 1;
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= n - i + 1; j++)
		{
			if(a[i])
			{
				for(int t = j; t <= n - i; t++)
					(dp[i+1][t] += dp[i][j]) %= mod;
			}
			else {
				for(int t = 1; t < j; t++)
					(dp[i+1][t] += dp[i][j]) %= mod;
			}
		}
	printf("%d\n", dp[n][1]);
	return 0;
}
