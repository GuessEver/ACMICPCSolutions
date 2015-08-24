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
const int Base = 1000000 + 10;
int cnt[2 * Base];
struct node
{
    int y, x, xx;
} a[1000], b[1000];
vector<int> add_Interval(int x, int y, vector<int> v)
{
    vector<int> vv;
    int sz = v.size();
    for(int i = 0; i < sz; i += 2)
    {
        if((v[i] < x && v[i + 1] >= x) ||
                (v[i] <= y && v[i + 1] > y))
        {
            x = min(x, v[i]);
            y = max(y, v[i + 1]);
        }
    }
    for(int j = 0; j < sz; j += 2)
    {
        if(v[j + 1] < x || v[j] > y)
        {
            vv.PB(v[j]);
            vv.PB(v[j + 1]);
        }
    }
    vv.PB(x), vv.PB(y);
    sort(vv.begin(), vv.end());
    return vv;
}
vector<int> cross(vector<int> x, vector<int> y)
{
    vector<int> vv;
    for(int i = 0; i < (int)x.size(); i += 2)
        for(int j = 0; j < (int)y.size(); j += 2)
        {
            int xx = max(x[i], y[j]), yy = min(x[i + 1], y[j + 1]);
            if(xx < yy)
            {
                vv.PB(xx);
                vv.PB(yy);
            }
        }
    sort(vv.begin(), vv.end());
    return vv;
}
int n, m;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    IN(n), IN(m);
    for(int i = 0; i < n; ++i)
    {
        IN(a[i].y), IN(a[i].x);
    }
    for(int i = 0; i < m; ++i)
    {
        IN(b[i].y), IN(b[i].x), IN(b[i].xx);
    }
    for(int i = 0; i < n; ++i)
    {
        vector<int> x, y;
        for(int j = 0; j < m; ++j)
        {
            if(a[i].y > b[j].y)
                x = add_Interval(b[j].x, b[j].xx + 1, x);
            else
                y = add_Interval(b[j].x, b[j].xx + 1, y);
        }
        x = cross(x, y);
        for(int j = 0; j < (int)x.size(); ++j)
        {
            cnt[a[i].x - x[j] + Base] += (j & 1) ? 1 : -1;
        }
    }
    int ans = 0, sum = 0;
    for(int i = 0; i < Base + Base; ++i)
        if(cnt[i])
        {
            sum += cnt[i];
            if(ans < sum)
                ans = sum;
        }
    printf("%d\n", ans);
    return 0;
}
