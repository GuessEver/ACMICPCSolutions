#include <cstdio>
#include <cstring>
#include <algorithm>
const int mod = 1000000000 + 7;
const int N = 1000 + 10;
int a[N], b[N];
int n, m;
int dp[N][N];
int sum[N][N]; // sum[j][i]
#define ADD(x, y) if((x += y) >= mod) x -= mod;
char c;
int In()
{
	int num = 0;
	c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9')
	{
		num = num * 10 + c - '0';
		c = getchar();
	}
	return num;
}
int main()
{
	int T; T = In();
	for(int cas = 1; cas <= T; cas++)
	{
		n = In();
		m = In();
		for(int i = 1; i <= n; i++) b[i] = a[i] = In();
		std::sort(b + 1, b + 1 + n);
		int tt = std::unique(b + 1, b + 1 + n) - b;
		// printf("tt = %d\n", tt);
		for(int i = 1; i <= n; i++)
			a[i] = std::lower_bound(b + 1, b + tt, a[i]) - b;
		// for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
		memset(sum, 0, sizeof(sum));
		memset(dp, 0, sizeof(dp));
		int x, pos;
		for(int i = 1; i <= n; i++)
		{
			dp[i][1] = 1;
			x = a[i], pos = 1;
			for(; x < N; x += x & -x) ADD(sum[pos][x], 1);
			for(int j = 2; j <= m; j++)
			{
				x = a[i] - 1, pos = j - 1;
				for(; x > 0; x -= x & -x) ADD(dp[i][j], sum[pos][x]);
				x = a[i], pos = j;
				for(; x < N; x += x & -x) ADD(sum[pos][x], dp[i][j]);
			}
		}
		int res = 0;
		for(int i = 1; i <= n; i++) ADD(res, dp[i][m]);
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
