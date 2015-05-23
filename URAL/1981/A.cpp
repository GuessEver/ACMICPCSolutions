#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	if(n == 4) puts("0 2");
	else if(n == 5) puts("0 0");
	else if(n % 2 == 1)
	{
		long long res1 = 1ll * n * ((n - 3) / 2);
		printf("%lld 0\n", res1);
	}
	else if(n % 2 == 0)
	{
		long long res11 = 1ll * n * ((n - 4) / 2) / 2;
		long long res12 = 1ll * n * ((n - 2) / 2) / 2;
		long long res1 = res12;
		long long res2 = res11 + res12;
		if((n - 4) / 2 > 1) res1 += res11;
		printf("%lld %lld\n", res1, res2);
	}
	return 0;
}
