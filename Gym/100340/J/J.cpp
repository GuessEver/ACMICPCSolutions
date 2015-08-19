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
int n, k;
struct edge
{
    int next, to;
} e[NUM << 1];
int head[NUM], tot;
void init()
{
    memset(head, -1, sizeof(head));
    tot = 0;
}
void add_edge(int u, int v)
{
    e[tot] = (edge) {head[u], v};
    head[u] = tot++;
}
int ans[NUM], cnt;
int sz[NUM];
void dfs(int u, int pree)
{
    sz[u] = 1;
    int szmax = 0, id = 0;
    for(int i = head[u]; ~i; i = e[i].next)
        if((i ^ 1) != pree)
        {
            dfs(e[i].to, i);
            if(sz[e[i].to] > szmax)
            {
                szmax = sz[e[i].to];
                id = i;
            }
            sz[u] += sz[e[i].to];
        }
    if(sz[u] > k)
    {
        sz[u] -= szmax;
        ans[cnt++] = id;
    }
    if(sz[u] == k)
    {
        if(pree != -1)
            ans[cnt++] = pree;
        sz[u] = 0;
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif
    IN(n), IN(k);
    init();
    int u, v;
    for(int i = 1; i < n; ++i)
    {
        IN(u), IN(v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, -1);
    int limit = 2 * n / k + (2 * n % k > 0);
    if(cnt > limit)
        puts("-1");
    else
    {
        printf("%d\n", cnt);
        for(int i = 0; i < cnt; ++i)
            printf("%d ", (ans[i] >> 1) + 1);
    }
    return 0;
}
