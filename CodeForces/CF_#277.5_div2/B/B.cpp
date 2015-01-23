#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 100 + 10;

int n, m, a[N], b[N];
int vis[N], map[N][N], pre[N];
int ttt = 0;

bool search(int x)
{
	for(int i = 1; i <= m; i++)
	{
		if(map[x][i] && vis[i] != ttt)
		{
			vis[i] = ttt;
			if(pre[i] == -1 || search(pre[i]))
			{
				pre[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(abs(a[i] - b[j]) <= 1)
				map[i][j] = 1;
	memset(pre, -1, sizeof(pre));
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		++ttt;
		res += search(i);
		//printf("%d %d\n", res, i);
	}
	printf("%d\n", res);
	return 0;
}
