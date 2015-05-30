#include <cstdio>
#include <cstring>
#include <queue>
using std::priority_queue;

const int N = 100000 + 10;

int n, K;
int a[N];
struct Link{
	int y;
	Link *next;
}*head[N];
int father[N];
struct Node{
	long long max; int id;
	bool operator < (const Node &b) const
	{
		return max < b.max;
	}
}val[N];
priority_queue<Node> Q;
bool done[N];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x)
{
	if(!head[x])
	{
		val[x].max = a[x];
		val[x].id = x;
		return;
	}
	int k = -1;
	for(Link *p = head[x]; p; p = p -> next)
	{
		father[p->y] = x;
		dfs(p -> y);
		if(k == -1 || val[p->y].max > val[k].max) k = p -> y;
	}
	val[x] = val[k]; val[x].max += a[x];
}

long long solve()
{
	if(Q.empty()) return 0;
	Node now = Q.top(); Q.pop();
	int x = now.id; done[x] = 1;
	while(x != 1 && !done[father[x]])
	{
		x = father[x]; done[x] = 1;
		for(Link *p = head[x]; p; p = p -> next)
			if(!done[p->y]) Q.push(val[p->y]);
	}
	return now.max;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(done, 0, sizeof(done));
		memset(head, 0, sizeof(head));
		scanf("%d%d", &n, &K);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y);
		}
		dfs(1);
		//for(int i = 1; i <= n; i++) printf("%d %d\n", val[i].max, val[i].id);
		while(!Q.empty()) Q.pop();
		Q.push(val[1]);
		long long res = 0;
		while(K--) res += solve();
		printf("Case #%d: %lld\n", cas, res);
	}
	return 0;
}
