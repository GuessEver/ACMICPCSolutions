#include<cstdio>
#include<cstring>
#include <algorithm>

int n = 10;
int cap[20][20];
int f[2000][20][20];

int main()
{
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) scanf("%d", &cap[i][j]);
	int tot = (1 << n);
	f[(1 << cap[1][1])][1][1] = cap[1][1];
	for(int S = 0; S < tot; S++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				int &tmp1 = f[S|(1 << cap[i+1][j])][i+1][j];
				int &tmp2 = f[S|(1 << cap[i][j+1])][i][j+1];
				tmp1 = std::min(tmp1, f[S][i][j] + cap[i+1][j]);
				tmp2 = std::min(tmp2, f[S][i][j] + cap[i][j+1]);
			}
	printf("%d\n", f[tot-1][n][n]);
	return 0;
}
