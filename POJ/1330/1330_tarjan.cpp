// poj 1330 (changed something)
// LCA tarjan
#include <cstdio>
#include <cstring>

const int N = 10000 + 10;

int n;
struct Link{int y, idx; Link *next;}*head[N], *ask[N];
int tx, ty;
bool in[N], vis[N];
int f[N];
int ans[N]; // Query Answer

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}
void inAsk(int x, int y, int idx)
{
	Link *p = new Link;
	p -> y = y;
	p -> idx = idx;
	p -> next = ask[x];
	ask[x] = p;
}

int getroot(int x)
{
	return f[x] == x ? x : f[x] = getroot(f[x]);
}

void LCA(int x)
{
	vis[x] = 1;
	f[x] = x;
	for(Link *p = ask[x]; p; p = p -> next)
		if(vis[p->y]) ans[p->idx] = getroot(p->y);
	for(Link *p = head[x]; p; p = p -> next)
		if(!vis[p->y])
		{
			LCA(p->y);
			f[p->y] = x;
		}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(head, 0, sizeof(head));
		memset(ask, 0, sizeof(ask));
		memset(in, 0, sizeof(in));
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			inLink(x, y);
			in[y] = 1;
		}
		int q = 1;// the number of query
		for(int i = 1; i <= q; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inAsk(x, y, i); inAsk(y, x, i);
		}
		int root = -1;
		for(int i = 1; i <= n; i++)
			if(!in[i]) {root = i; break;}
		LCA(root);
		for(int i = 1; i <= q; i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
