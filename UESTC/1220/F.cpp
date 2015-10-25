#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;
const int N = 100000 + 10;
int n, m;
int a[N], b[N], c[N], type[N];
struct Link{
	int y, z;
	Link *next;
}*head[N];
long long dist[N];
bool inQ[N];
queue<int> Q;

void inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y; p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

bool spfa(int S)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(inQ, 0, sizeof(inQ));
	dist[S] = 0; inQ[S] = 1; Q.push(S);
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); inQ[x] = 0;
		for(Link *p = head[x]; p; p = p -> next)
			if(dist[x] + p -> z < dist[p->y])
			{
				dist[p->y] = dist[x] + p -> z;
				if(!inQ[p->y])
				{
					Q.push(p -> y);
					inQ[p -> y] = 1;
				}
			}
	}
	for(int i = 1; i <= m; i++) if(type[i] == 2 && dist[i] == dist[0]) return 0;
	return 1;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &type[i]);
		memset(head, 0, sizeof(head));
		for(int i = 1; i <= n; i++) inLink(b[i], a[i], c[i]);
		for(int i = 1; i <= m; i++) if(type[i] == 0) inLink(m + 1, i, 0);
		long long res = 0;
		if(!spfa(m + 1)) res = -1;
		else {
			for(int i = 1; i <= m; i++) if(type[i] == 2) res += dist[i];
		}
		printf("Case #%d: %lld\n", cas, res);
	}
	return 0;
}
