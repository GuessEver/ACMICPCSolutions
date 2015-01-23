#include <cstdio>

int n, k, g[10][210];

int main()
{
	scanf("%d%d", &n, &k);
	for(int j = 0; j <= n; j++) g[1][j] = 1;
	for(int i = 2; i <= k; i++)
		for(int j = 0; j <= n; j++)
		{
			if(j >= i) g[i][j] = g[i-1][j] + g[i][j-i];
			else g[i][j] = g[i-1][j];
		}
	printf("%d\n", g[k][n-k]);
	return 0;
}
