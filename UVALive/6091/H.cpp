#include <cstdio>
#include <cstring>

int n, m;
int hash[600];
int ne, np;
struct Link {int y; Link *next;}*head[600];
bool edge[600][600];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x)
{
	np++;
	hash[x] = 1;
	for(Link *p = head[x]; p; p = p -> next)
	{
		if(!edge[x][p->y])
		{
			ne++;
			edge[x][p->y] = edge[p->y][x] = 1;
		}
		if(!hash[p->y]) dfs(p->y);
	}
}

int solve()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(!hash[i])
	{
		ne = np = 0;
		dfs(i);
		//printf("%d %d\n", ne, np);
		if(np == ne + 1) cnt++;
	}
	return cnt;
}

int main()
{
	//freopen("H.in", "r", stdin);
	int cas = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		memset(hash, 0, sizeof(hash));
		memset(head, 0, sizeof(head));
		memset(edge, 0, sizeof(edge));
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y); inLink(y, x);
		}
		printf("Case %d: ", ++cas);
		int res = solve();
		if(res == 0) printf("No trees.\n");
		else if(res == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", res);
	}
	return 0;
}
