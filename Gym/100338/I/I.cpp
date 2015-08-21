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
int n, c;
int a[110];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("tvshow.in", "r", stdin);
    freopen("tvshow.out", "w", stdout);
#endif
    IN(n), IN(c);
    for(int i = 1; i <= n; ++i) IN(a[i]);
    double now, ans = 100, p;
    for(int i = 0; i <= n; ++i)
    {
        now = 100.0;
        p = 1.0;
        for(int j = 1; j <= n; ++j)
        {
            if(i == j)
            {
                if(now <= c) break;
                now -= c;
                double pp = p, tnow = now;
                pp = pp * (1.0 - 0.01 * a[j]);
                p = p * 0.01 * a[j];
                now += now;
                ans = max(ans, pp * tnow + p * now);
                for(int k = j + 1; k <= n; ++k)
                {
                    pp = pp * 0.01 * a[k];
                    p = p * 0.01 * a[k];
                    tnow += tnow;
                    now += now;
                    ans = max(ans, pp * tnow + p * now);
                }
                break;
            }
            else
            {
                p = p * 0.01 * a[j];
                now += now;
                ans = max(ans, p * now);
            }
        }
    }
    printf("%.9f\n", ans);
    return 0;
}
