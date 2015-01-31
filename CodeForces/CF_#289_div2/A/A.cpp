#include <cstdio>

int n, a[20][20];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i][1] = a[1][i] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= n; j++)
			a[i][j] = a[i-1][j] + a[i][j-1];
	int res = a[1][1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] > res) res = a[i][j];
	printf("%d\n", res);
	return 0;
}
