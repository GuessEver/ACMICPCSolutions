#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		int m = n - n / 2;
		n /= 2;
		printf("%lld\n", 1ll*n*m);
	}
	return 0;
}
