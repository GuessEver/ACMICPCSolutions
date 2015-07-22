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
const int NUM = 100010;
LL mod = INF;
LL ans;
LL l[NUM], r[NUM];
int a[NUM], n;
LL pos[NUM];
vector<int> v[10001];
void init()
{
    for(int i = 1; i <= 10000; i++)
    {
        for(int j = 1; j * j <= i; j++)
            if(i % j == 0)
                v[i].push_back(j), v[i].push_back(i/j);
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    LL i, j;
    init();
    while(~scanf("%d", &n))
    {
        for(i = 1; i <= n; i++)
        {
            IN(a[i]);
            l[i] = 0;
            r[i] = n + 1;
        }
        memset(pos, 0, sizeof(pos));
        for(i = 1; i <= n; i++)
        {
            for(j = v[a[i]].size() - 1; j >= 0; j--)
                l[i] = max(l[i], pos[v[a[i]][j]]);
            pos[a[i]] = max(pos[a[i]], i);
        }
        for(i = 0; i <= 10000; i++)
            pos[i] = n + 1;
        for(i = n; i > 0; i--)
        {
            for(j = v[a[i]].size() - 1; j >= 0; j--)
                r[i] = min(r[i], pos[v[a[i]][j]]);
            pos[a[i]] = min(pos[a[i]], i);
        }
        ans = 0;
        for(i = 1; i <= n; i++)
            ans = (ans + (i - l[i]) * (r[i] - i) % mod) % mod;
        printf("%I64d\n", ans);
    }
    return 0;
}
