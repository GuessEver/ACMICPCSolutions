#include <cstdio>
#include <cstdlib>
#include <cstring>

const int N = 100 + 10;

int n, m;
int a[N][N], b[N][N];

void find(int i, int j, int &x, int &y)
{
	for(int k = 1; k <= n; k++)
		if(a[k][j] == -1)
		{
			x = k, y = j;
			return;
		}
	for(int k = 1; k <= m; k++)
		if(a[i][k] == -1)
		{
			x = i, y = k;
			return;
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &b[i][j]);
	memset(a, -1, sizeof(a));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(b[i][j] == 0)
			{
				for(int k = 1; k <= n; k++) a[k][j] = 0;
				for(int k = 1; k <= m; k++) a[i][k] = 0;
			}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(b[i][j] == 1)
			{
				int x = -1, y = -1;
				find(i, j, x, y);
				if(x == -1 && y == -1)
				{
					puts("NO");
					return 0;
				}
				//a[x][y] = 1;
			}
	puts("YES");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++) printf("%d ", abs(a[i][j]));
		printf("%d\n", abs(a[i][m]));
	}
	return 0;
}
