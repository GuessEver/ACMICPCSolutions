#include <cstdio>
#include <cstring>
const int N = 100 + 10;
const int mod = 1000000000 + 7;
int n, a[N];
char op[N];
long long sum[N][N], num[N][N], C[N][N];
bool vis[N][N];

long long solve(int l, int r)
{
	if(vis[l][r]) return sum[l][r];
	vis[l][r] = 1; sum[l][r] = num[l][r] = 0;
	if(l == r)
	{
		num[l][r] = 1;
		return sum[l][r] = a[l];
	}
	for(int i = l; i < r; i++)
	{
		long long left = solve(l, i);
		long long right = solve(i+1, r);
		long long CC = C[r-l-1][i-l];
		if(op[i] == '+')
			sum[l][r] += ((left * num[i+1][r] + right * num[l][i]) % mod * CC % mod + mod) % mod;
		else if(op[i] == '-')
			sum[l][r] += ((left * num[i+1][r] - right * num[l][i]) % mod * CC % mod + mod) % mod;
		else if(op[i] == '*')
			sum[l][r] += (left * right % mod * CC % mod + mod) % mod;
		((sum[l][r] %= mod) += mod) %= mod;
		(num[l][r] += num[l][i] * num[i+1][r] % mod * CC) %= mod;
	}
	return sum[l][r];
}

int main()
{
	C[0][0] = 1;
	for(int i = 1; i <= 100; i++)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	while(scanf("%d", &n) == 1)
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i < n; i++) scanf(" %c", &op[i]);
		printf("%lld\n", solve(1, n));
		/*for(int l = 1; l <= n; l++)
			for(int r = l; r <= n; r++)
				printf("[%d, %d]: %lld %lld\n", l, r, sum[l][r], num[l][r]);*/
	}
	return 0;
}
