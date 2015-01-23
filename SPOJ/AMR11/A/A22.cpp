#include <cstdio>
#include <cstring>

const int N = 500 + 10;

int n, m, a[N][N], f[N][N];
int pre[N][N];

int solve()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) 
		{
			f[i][j] = -0x3f3f3f3f;
			pre[i][j] = -1;
		}
	f[1][1] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1;j <= m; j++)
		{
			int tmp = f[i-1][j] + a[i][j];
			if(i > 1 && tmp >= f[i][j]) 
			{
				f[i][j] = f[i-1][j] + a[i][j];
				if(pre[i][j] == -1 || tmp > 0) pre[i][j] = 1;
			}
			tmp = f[i][j-1] + a[i][j];
			if(j > 1 && tmp >= f[i][j])
			{
				f[i][j] = f[i][j-1] + a[i][j];
				if(pre[i][j] == -1 || tmp > 0) pre[i][j] = 2;
			}
		}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= m; j++) printf("%d ", f[i][j]);
		printf("\n");
	} printf("\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= m; j++) printf("%d ", pre[i][j]);
		printf("\n");
	} printf("\n===========\n");
	int x = n, y = m;
	int res = f[x][y];
	while(1)
	{
		if(pre[x][y] == 1) x--;
		if(pre[x][y] == 2) y--;
		if(f[x][y] < res) res = f[x][y];
		if(x == 1 && y == 1) break;
	}
	return 1 - res;	
}

int main()
{
	freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", solve());
	}
	return 0;
}
