#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using std::queue;
using std::min;

const int N = 1000 * 3;
const int M = 10000 * 3;
const int inf = 0x3f3f3f3f;

struct EG{int from,to,flow,cost,next;}edge[M*2];
int head[N], L;
int n, m;
queue<int> q;
int inQ[N], dist[N], pre[N];
int S, T;

void add_edge(int a,int b,int c,int d)
{
	edge[L]=(EG){a,b,c,+d,head[a]};
	head[a]=L++;
	edge[L]=(EG){b,a,0,-d,head[b]};
	head[b]=L++;
}

bool spfa()
{
	memset(inQ, 0, sizeof(inQ));
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		inQ[x] = 0;
		for(int i = head[x]; i != -1; i = edge[i].next)
		{
			if(edge[i].flow && dist[edge[i].to] > dist[x] + edge[i].cost)
			{
				pre[edge[i].to] = i;
				dist[edge[i].to] = dist[x] + edge[i].cost;
				if(!inQ[edge[i].to])
				{
					inQ[edge[i].to] = 1;
					q.push(edge[i].to);
				}
			}
		}
	}
	return dist[T] != inf;
}
void MFMC()
{
	int mincost = 0, maxflow = 0;
	while(spfa())
	{
		int res = inf;
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			res = min(res, edge[pre[i]].flow);
		}
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			edge[pre[i]].flow -= res;
			edge[pre[i] ^ 1].flow += res;
		}
		maxflow += res;
		mincost += res * dist[T];
		//printf("%d %d %d\n", maxflow, mincost, dist[T]);
	}
	printf("%d\n", mincost);
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		S = 1; T = n*2;
		memset(head, -1, sizeof(head));
		memset(edge, 0, sizeof(edge)); L = 0;
		memset(pre, -1, sizeof(pre));
		add_edge(1, 2, 2, 0);
		add_edge(n*2-1, n*2, 2, 0);
		for(int i = 2; i < n; i++)
			add_edge(i*2-1, i*2, 1, 0);
		for(int i = 1; i <= m; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add_edge(a*2, b*2-1, 1, c);
		}
		//puts("--");
		MFMC();
	}
	return 0;
}
