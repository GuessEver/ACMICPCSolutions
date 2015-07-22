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
#include <climits>
#define INF 1000000007
#define MP make_pair
const double EPS = 1e-10, PI = acos(-1.0);
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
const int MAXV = 2020, MAXE = 60060;
struct node
{
    int v, w;
};
int n, m;
vector<node> g[MAXV];
struct edge {int to, cap, rev;};
vector <edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int d[MAXV];
int vis[MAXV];
void add_edge(int from, int to)
{
    G[from].push_back((edge) {to, 1, G[to].size()});
    G[to].push_back((edge) {from, 0, G[from].size() - 1 });
}
void add_edge1(int u, int v, int w)
{
    g[u].push_back((node) {v, w});
    g[v].push_back((node) {u, w});
}
void init()
{
    for(int i = 0; i < MAXV; i++)
    {
        g[i].clear();
        G[i].clear();
    }
}

bool shortest_path()
{
    priority_queue <P, vector<P>, greater <P> > que;
    for(int i = 2; i <= n; i++)
        d[i] = INF;
    d[1] = 0;
    que.push(P(0, 1));
    int i, u, v, w;
    P p;
    while(!que.empty())
    {
        p = que.top(); que.pop();
        u = p.second;
        if(d[u] < p.first) continue;
        for(i = 0; i < g[u].size(); i++)
        {
            v = g[u][i].v, w = g[u][i].w;
            if(d[v] > w + d[u])
            {
                d[v] = w + d[u];
                que.push(P(d[v], v));
            }
        }
    }
    return d[n] != INF;
}
void getG(int u)
{
    vis[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i].v, w = g[u][i].w;
        if(d[v] + w == d[u])
        {
            add_edge(u, v);
            add_edge(v, u);
            if(!vis[v])
                getG(v);
        }
    }
}
int getAns2()
{
    memset(vis, 0, sizeof(vis));
    queue<P> que;
    que.push(P(1, 0));
    vis[1] = 1;
    while(!que.empty())
    {
        P p = que.front();
        que.pop();
        if(p.first == n) return p.second;
        int u = p.first;
        for(int i = 0; i < G[u].size(); i++)
            if(!vis[G[u][i].to])
            {
                vis[G[u][i].to] = 1;
                que.push(P(G[u][i].to, p.second + 1));
            }
    }
    return 0;
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue <int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i = 0; i < G[v].size(); i++)
        {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0)
            {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++)
    {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    for(;;)
    {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0)
        {
            flow += f;
        }
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int i, j;
    int u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        init();
        for(i = 0; i < m; i++)
        {
            IN(u), IN(v), IN(w);
            add_edge1(u, v, w);
        }
        shortest_path();
        memset(vis, 0, sizeof(vis));
        getG(n);
        int ans1 = max_flow(n, 1);
        int ans2 = m - getAns2();
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
