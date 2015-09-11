#include <cstdio>
#include <algorithm>
const int N = 1000000 + 10;
int n, m, a[N];
int dp[1010][1010];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) a[i] %= m;
	if(n > m) puts("YES");
	else {
		for(int i = 1; i <= n; i++)
		{
			dp[i][a[i]] = 1;
			for(int j = 0; j < m; j++)
				if(dp[i-1][j])
					dp[i][j] = dp[i][(j + a[i]) % m] = 1;
		}
		puts(dp[n][0] ? "YES" : "NO");
	}
	return 0;
}
