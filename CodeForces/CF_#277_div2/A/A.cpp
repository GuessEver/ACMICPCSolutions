#include <cstdio>

int main()
{
	long long n; scanf("%I64d", &n);
	long long ans = n / 2;
	if(n % 2 != 0) ans -= n;
	printf("%I64d\n", ans);
	return 0;
}
