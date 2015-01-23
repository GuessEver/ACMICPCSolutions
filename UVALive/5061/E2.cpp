#include <cstdio>
#include <cstring>

const int N = 50000 + 10;

int n, v[N];
struct Link{int y; Link *next;}*head[N];
bool vis[N];
bool found;

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x, int tar, int power)
{
	vis[x] = 1;
	if(x == tar) 
	{
		found = 1;
		v[x] += found * power;
		return;
	}
	for(Link *p = head[x]; p; p = p -> next)
	{
		if(!vis[p->y]) dfs(p->y, tar, power);
		if(found) break;
	}
	v[x] += found * power;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(v, 0, sizeof(v));
		scanf("%d", &n);
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y); inLink(y, x);
		}
		int q; scanf("%d", &q);
		while(q--)
		{
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			found = (a == b);
			memset(vis, 0, sizeof(vis));
			dfs(a, b, c);
		}
		printf("Case #%d:\n", cas);
		for(int i = 0; i < n; i++) printf("%d\n", v[i]);
	}
	return 0;
}
