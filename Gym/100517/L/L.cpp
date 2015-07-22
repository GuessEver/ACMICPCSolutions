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
const int NUM = 150010;
struct node
{
    int l, r;
    void in() {scanf("%d%d", &l, &r);}
} g[2][NUM], ans[NUM];
int n, m;
void dfs(int u, int v, int &k, int fa, bool &f)
{
    if(!f || g[0][u].l == 0 || g[1][v].l == 0)
    {
        ans[fa].l = 0;
        ans[fa].r = 0;
        if(g[0][u].l + g[1][v].l > 0)
            f = false;
    }
    else
    {
        ans[fa].l = k++;
        ans[fa].r = k++;
        dfs(g[0][u].l, g[1][v].l, k, ans[fa].l, f);
        dfs(g[0][u].r, g[1][v].r, k, ans[fa].r, f);
    }
}

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
#endif
    int i, j;
    while(~scanf("%d", &n) && n)
    {
        for(i = 1; i <= n; i++)
            g[0][i].in();
        scanf("%d", &m);
        for(i = 1; i <= m; i++)
            g[1][i].in();
        i = 2;
        bool f = true;
        dfs(1, 1, i, 1, f);
        n = i - 1;
        printf("%d\n", n);
        for(i = 1; i <= n; i++)
        {
            printf("%d %d\n", ans[i].l, ans[i].r);
        }
    }
    return 0;
}
