#include <cstdio>
#include <algorithm>
using std::max;

int n, m, a[110][110], b[110][110];

int calc(int x, int y)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			b[i][j] = a[i][j];
	int pos = 0;
	for(int j = 1; j <= y; )
	{
		if(pos <= j) pos = j;
		j += max(1, a[x][j]);
	}
	for(int j = pos; j <= pos + b[x][y] - 1; j++) a[x][j] = 0;
	int res = b[x][y];
	for(int i = x - 1; i >= 1; i--)
		for(int j = 1; j <= m; j += max(1, b[i][j]))
		{
			if(!a[i][j]) continue;
			int len = a[i][j];
			bool flag = 1;
			for(int k = j; k <= j + len - 1; k++)
				if(a[i+1][k]) { flag = 0; break; }
			if(!flag) continue;
			for(int k = j; k <= j + len - 1; k++)
			{
				a[i+1][k] = a[i][k];
				a[i][k] = 0;
				res++;
			}
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = b[i][j];
	return res;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && n && m)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%1d", &a[i][j]);
		int maxAns = 0;
		for(int i = n; i >= 1; i--)
		{
			for(int j = 1; j <= m; j+=max(1, a[i][j]))
			{
				if(!a[i][j]) continue;
				int res = calc(i, j);
				if(res > maxAns) maxAns = res;
				//printf("%d %d %d\n", i, j, res);
			}
		}
		printf("%d\n", maxAns);
	}
	return 0;
}
