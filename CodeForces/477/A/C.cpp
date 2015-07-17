#include <cstdio>

const long long mod = 1000000007ll;

long long a, b;

int main()
{	
	scanf("%I64d%I64d", &a, &b);
	long long ans = 0;
	for(long long m = 1; m < b; m++)
	{
		ans += (m * (((a+1) * b / 2 + 1) % mod) % mod) * (((a-1) * m + 1) % mod) % mod;
		ans %= mod;
	}
	printf("%I64d\n", ans % mod);
	return 0;
}
