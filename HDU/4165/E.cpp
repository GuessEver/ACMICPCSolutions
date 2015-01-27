#include <cstdio>

long long f[100];

int main()
{
	f[0] = f[1] = 1; f[2] = 2;
	for(int i = 3; i <= 30; i++)
		for(int j = 0; j < i; j++)
			f[i] += f[j] * f[i-j-1];
	int n; 
	while(scanf("%d", &n) == 1 && n)
		printf("%lld\n", f[n]);
	return 0;
}
