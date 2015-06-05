#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100 + 10;

int a[N], n, f[N][N], sum[N];

int calc(int l, int k, int r)
{
	return ((sum[k] - sum[l-1]) % 100) * ((sum[r] - sum[k]) % 100);
}

int solve(int l, int r)
{
	if(l == r) return 0;
	if(f[l][r] != -1) return f[l][r];
	f[l][r] = 0x3f3f3f3f;
	for(int k = l; k < r; k++) // [l, k] U [k+1, r]
		f[l][r] = std::min(f[l][r], solve(l, k) + solve(k+1, r) + calc(l, k, r));
	return f[l][r];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n); sum[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i-1] + a[i];
		}
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(1, n));
	}
	return 0;
}
