#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1000 + 10;
const int M = 2000 + 10;
int n, L;
struct Node {
	int a, v;
}a[N];
long long dp[2*M][3];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &L); L *= 2;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d", &a[i].a, &a[i].v);
			a[i].a *= 2;
		}
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
			for(int j = L; j >= 0; j--)
				for(int k = 0; k < 3; k++)
				{
					if(j + a[i].a <= L)
						dp[j+a[i].a][k] = std::max(dp[j+a[i].a][k], dp[j][k] + a[i].v);
					if(k < 2 && j + a[i].a / 2 <= L)
						dp[j+a[i].a/2][k+1] = std::max(dp[j+a[i].a/2][k+1], dp[j][k] + a[i].v);
				}
		long long res = 0;
		for(int i = 1; i <= n; i++) res = std::max(res, 0ll + a[i].v);
		for(int j = 0; j <= L; j++)
			for(int k = 0; k < 3; k++) res = std::max(res, dp[j][k]);
		printf("Case #%d: %lld\n", cas, res);
	}
	return 0;
}
