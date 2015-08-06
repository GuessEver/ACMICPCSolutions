#include <cstdio>

int n;
int mod = 1000000000 + 7;

int mul(int x, int y)
{
	if(y == 0) return 1;
	if(y & 1) return 1ll * mul(1ll * x * x % mod, y / 2) * x % mod;
	return mul(1ll * x * x % mod, y / 2) % mod;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d\n", ((mul(2, n-1) - 1) % mod + mod) % mod);
	}
	return 0;
}
