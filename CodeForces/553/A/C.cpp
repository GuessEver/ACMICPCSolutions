#include <cstdio>
#include <algorithm>

const int mod = 1000000007;
int k, n, a[1010];
int C[1010][1010];

int main()
{
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &a[i]);
		n += a[i];
	}
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= 1000; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
	}
	int res = 1;
	for(int i = k; i >= 2; i--)
	{
		res = 1ll * res * C[n-1][a[i]-1] % mod;
		n -= a[i];
	}
	printf("%d\n", res);
	return 0;
}
