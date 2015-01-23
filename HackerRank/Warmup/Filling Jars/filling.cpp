#include <cstdio>

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	long long res = 0;
	while(m--)
	{
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		res += 1ll * k * (b - a + 1);
	}
	res /= n;
	printf("%lld\n", res);
}
