#include <cstdio>

const int mod = 1000000000 + 7;

int f[100];

int main()
{
	int x, y, k;
	scanf("%d%d%d", &x, &y, &k);
	f[1] = x; f[2] = y;
	for(int i = 3; i <= 90; i++) f[i] = f[i-1] - f[i-2];
	if(k > 6)
	{
		k -= 6;
		k %= 6;
		k += 6;
	}
	printf("%d\n", ((f[k] % mod) + mod) % mod);
	return 0;
}
