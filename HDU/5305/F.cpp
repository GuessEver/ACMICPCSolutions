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
const int NUM = 100;
int n, m;
int deg[11];
struct node
{
    int cnt[9];
    node()
    {
        clear();
    }
    void clear()
    {
        memset(cnt, 0, sizeof(cnt));
    }
    bool operator < (const node &b) const
    {
        for(int i = 0; i < 9; i++)
            if(cnt[i] != b.cnt[i])
                return cnt[i] < b.cnt[i];
        return false;
    }
};

map<node, int> dp, tmp;
map<node, int>::iterator it;
struct edge
{
    int u, v;
    void in()
    {
        IN(u), IN(v);
        if(u > v) swap(u, v);
    }
    bool operator < (const edge &b) const
    {
        if(u == b.u) return v < b.v;
        return u < b.u;
    }
} e[NUM];

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int i, j;
    int T;
    IN(T);
    while(T--)
    {
        IN(n), IN(m);
        memset(deg, 0, sizeof(deg));
        for(i = 0; i < m; i++)
        {
            e[i].in();
            deg[e[i].u]++;
            deg[e[i].v]++;
        }
        bool f = 1;
        for(i = 1; i <= n; i++)
            if(deg[i] & 1)
            {
                puts("0");
                f = 0;
                break;
            }
        if(!f) continue;
        sort(e, e + m);
        dp.clear();
        tmp.clear();
        node a;
        a.clear();
        dp[a] = 1;
        for(i = 1, j = 0; j < m && i <= n; i++)
        {
            for(; j < m && e[j].u == i; j++)
            {
                for(it = dp.begin(); it != dp.end(); it++)
                {
                    a = it->FI;
                    a.cnt[e[j].u]++;
                    a.cnt[e[j].v]++;
                    tmp[a] += it->SE;
                    a.cnt[e[j].u] -= 2;
                    a.cnt[e[j].v] -= 2;
                    tmp[a] += it->SE;
                }
                dp = tmp;
                tmp.clear();
            }
            for(it = dp.begin(); it != dp.end(); it++)
                if((it->FI).cnt[i] == 0)
                    tmp.insert(*it);
            dp = tmp;
            tmp.clear();
        }
        a.clear();
        printf("%d\n", dp[a]);
    }
    return 0;
}
