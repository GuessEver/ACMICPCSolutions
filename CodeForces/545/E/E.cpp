#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;

const int N = 3 * 100000 + 10;

int n, m;
struct Link{
	int y, z;
	Link *next;
}*head[N];
int S;
struct Edge{
	int x, y, z, idx;
	bool operator < (const Edge &b) const
	{
		return z < b.z;
	}
}edge[N];
int L;

void inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y; p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

long long dist[N];
bool inQ[N];
queue<int> Q;

void spfa()
{
	memset(dist, 0x3f, sizeof(dist)); dist[S] = 0;
	Q.push(S); inQ[S] = 1;
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); inQ[x] = 0;
		for(Link *p = head[x]; p; p = p -> next)
			if(dist[p->y] > dist[x] + p->z)
			{
				dist[p->y] = dist[x] + p->z;
				if(!inQ[p->y])
				{
					inQ[p->y] = 1;
					Q.push(p->y);
				}
			}
	}
	//for(int i = 1; i <= n; i++) printf("%d ", dist[i]); puts("");
}

int f[N];
bool choose[N], done[N];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

void Solve()
{
	for(int i = 1; i <= n; i++) f[i] = i;
	std::sort(edge+1, edge+1+m);
	long long res = 0;
	for(int i = 1; i <= m; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		if(dist[edge[i].x] + edge[i].z == dist[edge[i].y])
		{
			if(done[edge[i].y]) continue;
			f[getroot(edge[i].x)] = getroot(edge[i].y);
			choose[edge[i].idx] = done[edge[i].y] = 1;
			res += edge[i].z;
		}
		if(dist[edge[i].y] + edge[i].z == dist[edge[i].x])
		{
			if(done[edge[i].x]) continue;
			f[getroot(edge[i].x)] = getroot(edge[i].y);
			choose[edge[i].idx] = done[edge[i].x] = 1;
			res += edge[i].z;
		}
	}
	printf("%I64d\n", res);
	for(int i = 1; i <= m; i++) if(choose[i]) printf("%d ", i);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		inLink(x, y, z);
		inLink(y, x, z);
		edge[i] = (Edge){x, y, z, i};
	}
	scanf("%d", &S);
	spfa();
	Solve();
	return 0;
}
