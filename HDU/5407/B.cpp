#include <cstdio>
#include <cmath>
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

int n;

int Solve(int p)
{
	int x = n;
	while((x + 1) % p == 0) x /= p;
	int cnt = 0;
	while(x) { x /= p; cnt++; }
	if(cnt != 0) cnt--;
	return cnt;
}

int main()
{
	prime::make(1000000);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		long long res = 1;
		for(int j = 0; j < prime::Cnt && prime::pri[j] <= n; j++)
		{
			int tmp = Solve(prime::pri[j]);
			(res *= mul(prime::pri[j], tmp)) %= mod;
		}
		printf("%lld\n", res);
	}
	return 0;
}
