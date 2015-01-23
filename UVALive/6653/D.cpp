#include <cstdio>

long long l;
int m, n;
const long long mod = 10000000000007ll;

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%lld%d%d", &l, &n, &m);
		l = l * l;
		long long ans = 0;
		long long tmp = 1;
		for(int i = 1; i < n; i++)
		{
			tmp *= l; l--;
			tmp %= mod;
		}
		for(int i = n; i <= m; i++)
		{
			tmp *= l; l--; tmp %= mod;
			ans = (ans + tmp) % mod;
		}
		printf("Case %d: %lld\n", cas, ans % mod);
	}
	return 0;
}
