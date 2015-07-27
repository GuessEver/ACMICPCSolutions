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
#include <bitset>
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
const int MAXV = 510, MAXE = 10010;
int n, m;
struct edge
{
    int next, to;
} e[MAXE << 1];
int head[MAXV], htot;
void init()
{
    memset(head, -1, sizeof(head));
    htot = 0;
}
void add_edge(int u, int v)
{
    e[htot] = (edge) {head[u], v};
    head[u] = htot++;
}
bitset<MAXV> vis, used;
int color[MAXV];
bool can;
void input()
{
    IN(n), IN(m);
    init();
    for(int i = 0; i < m; i++)
    {
        int u, v;
        IN(u), IN(v);
        add_edge(u, v);
        add_edge(v, u);
    }
}
void dfs(int u, int c[2], int f)
{
    f = !f;
    vis[u] = 0;
    for(int i = head[u]; ~i; i = e[i].next)
        if(vis.test(e[i].to))
        {
            if(color[e[i].to] == 0)
                color[e[i].to] = c[f];
            else if(color[e[i].to] != c[f])
            {
                can = false;
                return ;
            }
            dfs(e[i].to, c, f);
        }
        else if(color[e[i].to] == c[!f])
        {
            can = false;
            return ;
        }
}
bool solve(int u, int nowc, int colored, int cc)
{
    color[u] = nowc;
    vis.reset();
    used.set(u);
    for(int i = head[u]; ~i; i = e[i].next)
        vis.set(e[i].to);
    int c[2];
    for(int i = 1, j = 0; i <= 3; i++) if(i != nowc) c[j++] = i;
    if(colored == -1)
    {
        colored = e[head[u]].to;
        cc = 2;
        color[colored] = cc;
    }
    dfs(colored, c, c[1] == cc);
    if(!can) return false;
    for(int i = head[u]; ~i; i = e[i].next)
        if(!used[e[i].to])
        {
            if(!solve(e[i].to, color[e[i].to], u, nowc))
                return false;
        }
    return true;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("mayors.in", "r", stdin);
    freopen("mayors.out", "w", stdout);
#endif
    int i;
    input();
    memset(color, 0, sizeof(color));
    used.reset();
    can = true;
    solve(1, 1, -1, -1);
    if(can)
    {
        printf("Plan OK\n");
        for(i = 1; i <= n; i++)
        {
            if(color[i] == 1) putchar('R');
            else if(color[i] == 2) putchar('G');
            else putchar('B');
        }
        puts("");
    }
    else
    {
        printf("Plan failed\n");
    }
    return 0;
}
