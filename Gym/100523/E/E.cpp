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
const int NUM = 500010;
int maxn[NUM << 2], minn[NUM << 2], ans[NUM << 2], add[NUM << 2], len[NUM << 2];
#define LC (p<<1)
#define RC (p<<1|1)
#define MID int mid = (l + r)>>1
inline void push_down(int p)
{
    add[LC] += add[p];
    add[RC] += add[p];
    minn[LC] += add[p];
    minn[RC] += add[p];
    maxn[LC] += add[p];
    maxn[RC] += add[p];
    if(minn[LC] > 0) ans[LC] = len[LC];
    else if(maxn[LC] == 0) ans[LC] = 0;
    if(minn[RC] > 0) ans[RC] = len[RC];
    else if(maxn[RC] == 0) ans[RC] = 0;
    add[p] = 0;
}
void build(int p, int l, int r)
{
    len[p] = r - l + 1;
    if(l == r) return ;
    MID;
    build(LC, l, mid);
    build(RC, mid + 1, r);
}
void update(int p, int l, int r, int L, int R, int val)
{
    if(L <= l && r <= R)
    {
        add[p] += val;
        minn[p] += val;
        maxn[p] += val;
        if(minn[p] > 0) ans[p] = len[p];
        else if(maxn[p] == 0) ans[p] = 0;
        else
        {
            if(add[p]) push_down(p);
            MID;
            update(LC, l, mid, L, R, 0);
            update(RC, mid + 1, r, L, R, 0);
            ans[p] = ans[LC] + ans[RC];
        }
//        cout << l << ' ' << r << ' ' << ans[p] << endl;
        return ;
    }
    if(add[p]) push_down(p);
    MID;
    if(L <= mid) update(LC, l, mid, L, R, val);
    if(R > mid) update(RC, mid + 1, r, L, R, val);
    minn[p] = min(minn[LC], minn[RC]);
    maxn[p] = max(maxn[LC], maxn[RC]);
    ans[p] = ans[LC] + ans[RC];
//    cout << l << ' ' << r << ' ' << ans[p] << ' ' << minn[p] << ' ' << maxn[p] << endl;
}
int n, m, d, l, x[NUM];
inline void solve(int pos, int val)
{
    int st = lower_bound(x + 1, x + 1 + n, pos - l) - x;
    int ed = upper_bound(x + 1, x + 1 + n, pos + l) - x - 1;
//    cout << "# " << st << ' ' << ed << ' ' << val << endl;
    if(st <= ed) update(1, 1, n, st, ed, val);
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &d, &l);
    for(int i = 2; i <= n; i++) scanf("%d", &x[i]);
    build(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int a;
        scanf("%d", &a);
        solve(a, 1);
    }
    printf("%d\n", ans[1]);
    int p, r;
    for(int i = 1; i <= d; i++)
    {
        scanf("%d%d", &p, &r);
        solve(p, -1);
        solve(r, 1);
        printf("%d\n", ans[1]);
    }
    return 0;
}
