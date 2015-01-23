#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

const int N = 100000 + 10;
const int inf = 0x3f3f3f3f;

int n, m;
struct Link{int y, z; Link *next;}*head[N];
bool machine[N];
bool vis[N];
long long ans = 0;

Link* inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = head[x];
	return head[x] = p;
}

void dfs(int x, int minp)
{
	if(vis[x]) return;
	vis[x] = 1;
	if(machine[x])
	{
		if(minp == inf) ans += 0;
		else ans += minp;
		minp = inf;
	}
	for(Link *p = head[x]; p; p = p -> next)
	{
		dfs(p->y, min(minp, p->z));
		//vis[p->y] = 0;
	}
}

long long solve(int first)
{
	ans = 0;
	dfs(first, inf);
	return ans;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(machine, 0, sizeof(machine));
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(int i = 1; i < n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			Link *p1 = inLink(x, y, z);
			Link *p2 = inLink(y, x, z);
		}
		int k = -1;
		for(int i = 1; i <= m; i++)
		{
			int x; scanf("%d", &x);
			machine[x] = 1;
			k = x;
		}
		if(k == -1) puts("0");
		else printf("%I64d\n", solve(k));
	}
	return 0;
}
