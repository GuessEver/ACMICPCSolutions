#include <cstdio>
#include <cstring>
const int N = 1000000 + 10;
const int mod = 1000000000 + 7;

namespace prime{
	const int N = 1000000 + 10;
	int pri[N], h[N], Cnt;
	void make(int maxp) // O(2*N)
	{
		for(int i = 2; i <= maxp; i++)
		{
			if(!h[i]) pri[Cnt++] = i;
			for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
			{
				h[i * pri[j]] = true;
				if(i % pri[j] == 0) break;
			}
		}
	}
}
int mul(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res = 1ll * res * x % mod;
		y /= 2; x = 1ll * x * x % mod;
	}
	return res % mod;
}

int n, dp[N];

int Solve(int p)
{
	for(int i = p; i <= n; i += p)
	{
		if(i / p % p != 0) dp[i] = 1;
		else dp[i] = dp[i / p] + 1;
	}
	//printf("p = %d: %d %d %d %d %d\n", p, dp[1], dp[2], dp[3], dp[4], dp[5]);
	int res = 0, ans = 0;
	for(int i = n / p * p; i >= (n + 1) / 2; i -= p)
	{
		res += dp[i];
		res -= dp[(n-i+1)/p*p];
		if(res > ans) ans = res;
	}
	return ans;
}

int main()
{
	prime::make(1000000);
	int T; scanf("%d", &T);
	while(T--)
	//for(n = 1; n <= 100; n++)
	{
		//printf("%3d: ", n);
		scanf("%d", &n);
		long long res = 1;
		for(int j = 0; j < prime::Cnt && prime::pri[j] <= n; j++)
		{
			int tmp = Solve(prime::pri[j]);
			(res *= mul(prime::pri[j], tmp)) %= mod;
			//printf("%d ", tmp);
		}
		printf("%lld\n", res);
	}
	return 0;
}
