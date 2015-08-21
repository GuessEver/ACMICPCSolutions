#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
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
template<class T>
inline void U(T num) {if(num < 0)putchar('-'), num = -num; if(num > 9)U(num / 10); putchar(num % 10 + '0');}
//------------------------   code   ---------------------------------//
const int NUM = 100010;
const int MAXV = 20000 + 10, MAXE = NUM;
struct edge
{
    int next, from , to;
    LL cost;
    int id;
};
struct G
{
    vector<edge> e;
    vector<int> head;
    void init()
    {
        e.clear();
        head.clear();
        head.resize(MAXV, -1);
    }
    void add_edge(int u, int v, LL cost, int id)
    {
        e.PB((edge) {head[u], u,  v, cost, id});
        head[u] = (int)e.size() - 1;
    }
} g[2];
int n, m, s, t;
LL dist[2][MAXV];
void shortest_path(int S, int T, int k)
{
    priority_queue<P, vector<P>, greater<P> > que;
    for(int i = 1; i <= n; i++)
        dist[k][i] = LONG_LONG_MAX;
    dist[k][S] = 0;
    que.push(P(0, S));
    while(!que.empty())
    {
        P p = que.top(); que.pop();
        int u = p.SE;
        if(dist[k][u] < p.FI) continue;
        for(int i = g[k].head[u]; i != -1; i = g[k].e[i].next)
        {
            int v = g[k].e[i].to;
            if(dist[k][v] > dist[k][u] + g[k].e[i].cost)
            {
                dist[k][v] = dist[k][u] + g[k].e[i].cost;
                que.push(P(dist[k][v], v));
            }
        }
    }
}
int ans[MAXE << 1], ansi;
int vis[MAXE << 1];
void solve()
{
    priority_queue<P> que;
    que.push(P(dist[0][t], t));
    vis[t] = 1;
    while(!que.empty())
    {
        int u  = que.top().SE;
        que.pop();
        int cnt = 0;
        for(int i = g[1].head[u]; i != -1; i = g[1].e[i].next)
        {
            int v = g[1].e[i].to;
            LL w = g[1].e[i].cost;
            if(dist[0][v] + w == dist[0][u])
            {
                cnt++;
            }
        }
        bool f = que.empty() && (cnt == 1);
        for(int i = g[1].head[u]; i != -1; i = g[1].e[i].next)
        {
            int v = g[1].e[i].to;
            LL w = g[1].e[i].cost;
            if(dist[0][v] + w == dist[0][u])
            {
                if(f && !ans[g[1].e[i].id])
                {
                    ansi++;
                    ans[g[1].e[i].id] = 1;
                }
                if(!vis[v])
                {
                    vis[v] = 1;
                    que.push(P(dist[0][v], v));
                }
            }
        }
    }
}

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("important.in", "r", stdin);
    freopen("important.out", "w", stdout);
#endif
    int i, u, v, w;
    IN(n), IN(m);
    s = 1, t = n;
    g[0].init(), g[1].init();
    for(i = 1; i <= m; i++)
    {
        IN(u), IN(v), IN(w);
        g[0].add_edge(u, v, w, i);
        g[0].add_edge(v, u, w, i);
        g[1].add_edge(v, u, w, i);
        g[1].add_edge(u, v, w, i);
    }
    shortest_path(s, t, 0);
    shortest_path(t, s, 1);
    solve();
    printf("%d\n", ansi);
    for(int i = 1; i <= m; ++i)
        if(ans[i])
            printf("%d ", i);
    return 0;
}
