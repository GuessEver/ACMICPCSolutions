#include <cstdio>

const int mod = 1000000000 + 7;

int T, k, a, b;
int f[100000+10];

int main()
{
	scanf("%d%d", &T, &k);
	for(int i = 0; i < k; i++) f[i] = 1;
	for(int i = k; i <= 100000; i++) f[i] = (f[i-1] + f[i-k]) % mod;
	for(int i = 1; i <= 100000; i++) f[i] = (f[i] + f[i-1]) % mod;
	while(T--)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", ((f[b] - f[a-1]) % mod + mod) % mod);
	}
	return 0;
}
