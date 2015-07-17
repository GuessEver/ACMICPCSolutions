#include <cstdio>
#include <cstring>

const int N = 100 + 10;

int n, m;
struct Link{int y, z; Link *next;}*head[N];
int ans[N][N];
int vis[N];

void inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

bool dfs(int x, int tar, int col)
{
	if(x == tar) return 1;
	if(vis[x]) return 0;
	vis[x] = 1;
	for(Link *p = head[x]; p; p = p->next)
		if(p->z == col)
		{
			if(dfs(p->y, tar, col)) return 1;
		}
	return 0;
}

int calc(int x, int y)
{
	int res = 0;
	for(int i = 1; i <= m; i++)
	{
		memset(vis, 0, sizeof(vis));
		if(dfs(x, y, i)) res++;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		inLink(x, y, z); inLink(y, x, z);
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
		{
			ans[i][j] = ans[j][i] = calc(i, j);
		}
	int q; scanf("%d", &q);
	while(q--)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", ans[a][b]);
	}
	return 0;
}
