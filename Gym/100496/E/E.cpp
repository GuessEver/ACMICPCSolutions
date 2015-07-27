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
LL a[3];
vector<LL> ans;
LL deal(LL b, LL c, LL &x, LL &y)
{
    LL a1[] = {b, c / 2, c - c / 2};
    LL a2[] = {1, c - 1, b};
    sort(a1, a1 + 3);
    sort(a2, a2 + 3);
    if(a1[1] > a2[1])
        x = c / 2, y = c - c / 2;
    else
        x = 1, y = c - 1;
    return max(a1[1], a2[1]);
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("eating.in", "r", stdin);
    freopen("eating.out", "w", stdout);
#endif
    int i;
    int cas = 1;
    while(IN(a[0]) + IN(a[1]) + IN(a[2]))
    {
        ans.clear();
        printf("Case #%d:\n", cas++);
        while(true)
        {
            sort(a, a + 3);
            if(a[0] == 0) break;
            if(a[1] == 1)
            {
                ans.PB(1);
                a[1] = a[2] / 2;
                a[2] = a[2] - a[1];
                continue;
            }
            LL x1, y1, x2, y2;
            if(deal(a[0], a[1], x1, y1) >= deal(a[0], a[2], x2, y2))
            {
                ans.PB(a[2]);
                a[1] = x1;
                a[2] = y1;
            }
            else
            {
                ans.PB(a[1]);
                a[1] = x2;
                a[2] = y2;
            }
        }
        printf("%d\n%I64d", (int)ans.size(), ans[0]);
        for(i = 1; i < (int)ans.size(); i++)
            printf(" %I64d", ans[i]);
        puts("");
    }
    return 0;
}
