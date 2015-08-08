#include <cstdio>

long long a[100];
int n;
long long f[100][100];

int main()
{
	for(int i = 1; i <= 60; i++) f[i][1] = i;
	for(int k = 2; k <= 60; k++)
		for(int i = 1; i <= 60; i++)
			f[i+1][k] = f[i][k] + f[i-2][k-1];
	for(int i = 1; i <= 60; i++)
		for(int j = 0; j <= 60; j++) a[i] += f[i][j];
	while(scanf("%d", &n) == 1) printf("%lld\n", a[n]);
	return 0;
}
