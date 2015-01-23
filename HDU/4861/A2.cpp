#include <cstdio>

int n, p;

int mul(int x, int y, int mod)
{
	if(y == 1) return x;
	if(y & 1) return mul(x % mod * x % mod, y / 2, mod) * x % mod;
	else return mul(x % mod * x % mod, y / 2, mod) % mod;
}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++)
	{
		int tmp = 0;
		for(int j = 1; j < p; j++)
		{
			int tt = 1;
			for(int k = 1; k <= i; k++) tt = tt % p * j % p;
			tmp = (tt + tmp) % p;
		}
		if(tmp) printf("%d %d\n",i, tmp);
	}
	return 0;
}
