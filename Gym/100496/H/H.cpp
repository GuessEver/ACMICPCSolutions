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
const int NUM = 100010;
LL n;
LL nodew[NUM];
struct edge
{
    LL w;
    int v;
};
vector<edge> g[NUM];
LL sum[NUM], dp[NUM];
LL ans;
int ansn;
void dfs(int u, int fa)
{
    dp[u] = 0;
    sum[u] = nodew[u];
    for(vector<edge>::iterator it = g[u].begin(); it != g[u].end(); it++)
        if(it->v != fa)
        {
            dfs(it->v, u);
            sum[u] += sum[it->v];
            dp[u] += dp[it->v] + sum[it->v] * it->w;
        }
}
void solve(int u, int fa)
{
    if(dp[u] < ans)
    {
        ans = dp[u];
        ansn = u;
    }
    for(vector<edge>::iterator it = g[u].begin(); it != g[u].end(); it++)
        if(it->v != fa)
        {
            dp[u] -= dp[it->v] + sum[it->v] * it->w;
            sum[u] -= sum[it->v];
            dp[it->v] += dp[u] + sum[u] * it->w;
            sum[it->v] += sum[u];
            solve(it->v, u);
            dp[it->v] -= dp[u] + sum[u] * it->w;
            sum[it->v] -= sum[u];
            dp[u] += dp[it->v] + sum[it->v] * it->w;
            sum[u] += sum[it->v];
        }
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
	freopen("house.in", "r", stdin);
	freopen("house.out", "w", stdout);
#endif
    int i;
    IN(n);
    for(i = 1; i <= n; i++)
        IN(nodew[i]);
    int u, v;
    LL w;
    for(i = 1; i < n; i++)
    {
        IN(u), IN(v), IN(w);
        g[u].PB((edge) {w, v});
        g[v].PB((edge) {w, u});
    }
    dfs(1, -1);
    ans = dp[1];
    ansn = 1;
    solve(1, -1);
    printf("%d %I64d\n", ansn, ans);
    return 0;
}
