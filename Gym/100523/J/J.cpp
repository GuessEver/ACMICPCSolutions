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
const int NUM = 3000010;
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
int k;
bool dfs(int u, int fa, int &sz)
{
    int siz = 1;
    for(int i = head[u]; ~i; i = e[i].next)
        if(e[i].to != fa)
        {
            if(!dfs(e[i].to, u, siz))
                return false;
        }
    if(siz < k) sz += siz;
    else if(siz > k) return false;
    return true;
}
int n;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int u;
    IN(n);
    init();
    for(int i = 2; i <= n; i++)
    {
        IN(u);
        add_edge(u, i);
        add_edge(i, u);
    }
    vector<int> ans;
    int sz, i;
    for(i = 1; i * i < n; i++)
        if(n % i == 0)
        {
            sz = 0;
            k = i;
            if(dfs(1, -1, sz) && sz == 0)
                ans.PB(n/i);
            k = n / i;
            sz = 0;
            if(dfs(1, -1, sz) && sz == 0)
                ans.PB(i);
        }
    sz = 0;
    if(i * i == n && dfs(1, -1, sz) && sz == 0)
        ans.PB(i);
    sort(ans.begin(), ans.end());
    printf("%d", ans[0]);
    for(int i = 1; i < (int)ans.size(); i++)
        printf(" %d", ans[i]);
    return 0;
}
