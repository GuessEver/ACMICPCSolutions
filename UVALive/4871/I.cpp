#include <cstdio>

const long long mod = 1000000;
int n;
long long f[1010][1010];

int main()
{
	f[1][1] = 1;
	for(int i = 2; i <= 1000; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			f[i][j] = (f[i][j-1] + f[i-1][j]) % mod;
			f[i][0] = (f[i][0] + f[i][j]) % mod;
		}
	}
	while(scanf("%d", &n) == 1 && n)
	{
		printf("%lld\n", f[n][0] % mod);
	}
	return 0;
}
