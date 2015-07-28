#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <deque>
#include <stack>
#include <climits>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
	template<class T>
inline T IN(T &num)
{
	num = 0;
	char c = getchar(), f = 0;
	while(c != '-' && (c < '0' || c > '9')) c = getchar();
	if(c == '-') f = 1, c = getchar();
	while('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
	if(f) num = -num;
	return num;
}
//------------------------   code   ---------------------------------//
const int NUM = 100010;
int n, m;
const int MAXV = 200;


struct edge {int to, cap, cost, rev; };

int V;//顶点数
vector <edge> G[MAXV];//图
int dist[MAXV];//最短距离
int prevv[MAXV], preve[MAXV];//最短路中的前驱结点和对应的边

void init()
{
	for(int i = 0; i < MAXV; i++)
		G[i].clear();
}

void add_edge(int from, int to, int cap, int cost)
{
	G[from].push_back((edge) {to, cap, cost, G[to].size()});
	G[to].push_back((edge) {from, 0, -cost, G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f)
{
	int res = 0;
	while(f > 0)
	{
		//Bellman_Ford算法
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool updata = true;
		while(updata)
		{
			updata = false;
			for(int v = 0; v < V; v++)
			{
				if(dist[v] == INF) continue;
				for(int i = 0; i < G[v].size(); i++)
				{
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost)
					{
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						updata = true;
					}
				}
			}
		}
		if(dist[t] == INF)
			return -1;//无解
		int d = f;
		for(int v = t; v != s; v = prevv[v])
		{
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * dist[t];
		for(int v = t; v != s; v = prevv[v])
		{
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
	//	freopen("in.txt", "w", stdout);
#endif
	int i;
	while(~scanf("%d%d", &n, &m))
	{
		int sum1 = 0, sum2 = 0;
		int u, v;
		init();
		V = n + 2;
		int s = 0, t = n + 1;
		for(i = 1; i <= n; i++)
		{
			IN(u), IN(v);
			sum1 += u;
			sum2 += v;
			add_edge(s, i, u, 0);
			add_edge(i, t, v, 0);
		}
		for(i = 1; i <= m; i++)
		{
			IN(u), IN(v);
			add_edge(u, v, INF, 1);
			add_edge(v, u, INF, 1);
		}
		int ans = -1;
		if(sum1 == sum2) ans = min_cost_flow(s, t, sum1);
		printf("%d\n", ans);
	}
	return 0;
}
