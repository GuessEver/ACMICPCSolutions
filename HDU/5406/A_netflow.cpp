#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;
const int inf = 0x3f3f3f3f;
const int N = 1000 * 2 + 10;
const int M = 1000 * 1000 * 2 + 10;

struct EG{int from,to,flow,cost,next;}edge[M];
int dist[N], pre[N], head[N], L;
int S, T;
queue<int> Q;
bool inQ[N];

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
	memset(dist, -1, sizeof(dist));
	dist[S] = 0; Q.push(S);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop(); inQ[x] = 0;
		for(int i = head[x]; i != -1; i = edge[i].next)
			if(edge[i].flow && dist[edge[i].to] < dist[x] + edge[i].cost)
			{
				pre[edge[i].to] = i;
				dist[edge[i].to] = dist[x] + edge[i].cost;
				if(!inQ[edge[i].to])
				{
					inQ[edge[i].to] = 1;
					Q.push(edge[i].to);
				}
			}
	}
	return dist[T] != 0;
}
int MFMC()
{
	int maxcost = 0, maxflow = 0;
	//while(spfa())
	for(int t = 1; t <= 2; t++)
	{
		if(!spfa()) break;
		int res = inf;
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			res = std::min(res, edge[pre[i]].flow);
		}
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			edge[pre[i]].flow -= res;
			edge[pre[i] ^ 1].flow += res;
		}
		maxflow += res;
		maxcost += res * dist[T];
		//printf("res = %d, dist = %d, %d %d\n", res, dist[T], maxflow, maxcost);
	}
	return maxcost;
}

struct Node{
	int a, b;
	bool operator < (const Node &y) const
	{
		if(a == y.a) return b < y.b;
		return a > y.a;
	}
}a[N];
int n;
inline int I(int x) { return x * 2; }
inline int O(int x) { return x * 2 + 1; }

int main()
{
	int ttt; scanf("%d", &ttt);
	while(ttt--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].a, &a[i].b);
		std::sort(a+1, a+1+n);
		//for(int i = 1; i <= n; i++) printf(" !! %d %d\n", a[i].a, a[i].b);
		memset(head, -1, sizeof(head));
		S = 1; T = O(n) + 1;
		for(int i = 1; i <= n; i++)
		{
			add_edge(S, I(i), 2, 0);
			add_edge(I(i), O(i), 1, 1);
			add_edge(O(i), T, 2, 0);
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j < i; j++)
				if(a[i].b >= a[j].b) add_edge(O(j), I(i), 1, 0);
		printf("%d\n", MFMC());
	}
	return 0;
}
