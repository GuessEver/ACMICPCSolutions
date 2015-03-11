#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

const int N = 100 + 10;

int n, a[N];
bool calc[N][N];
long long sum[N], f[N][N];

long long solve(int l, int r)
{
	if(l > r) return 0;
	if(calc[l][r]) return f[l][r];
	calc[l][r] = 1;
	long long tmp = 0;
	for(int k = l; k <= r; k++)
		tmp = std::min(tmp, std::min(solve(l, k), solve(k + 1, r)));
	return f[l][r] = sum[r] - sum[l-1] - tmp;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		memset(calc, 0, sizeof(calc));
		memset(f, 0, sizeof(f));
		long long res = solve(1, n);
		printf("%lld\n", res - (sum[n] - res));
	}
	return 0;
}
