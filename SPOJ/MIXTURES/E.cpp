#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fll;

int n, a[N];
long long sum[N];
long long f[N][N];

long long dp(int l, int r)
{
	if(f[l][r] != -1) return f[l][r];
	if(r - l == 0) return 0;
	f[l][r] = inf;
	for(int k = l; k < r; k++) // [l, k] [k+1, r]
	{
		long long left = dp(l, k);
		long long right = dp(k+1, r);
		long long suml = (sum[k] - sum[l-1]) % 100;
		long long sumr = (sum[r] - sum[k]) % 100;
		f[l][r] = std::min(f[l][r], left + right + suml * sumr);
	}
	return f[l][r];
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		memset(f, -1, sizeof(f));
		printf("%lld\n", dp(1, n));
	}
	return 0;
}
