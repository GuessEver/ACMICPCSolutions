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
//------------------------   solve  ---------------------------------//
/*维护pre[a], 表示前一个a出现的位置
	RMQ: 以r为时间轴, 位置r加1, pre[a[r]]减1, 每询问[L,R]在时间轴为
	R是询问区间[L,R]的和
	将每个询问的R修改为距离l最近的a[r]的位置
*/
//------------------------   code   ---------------------------------//
const int NUM = 200010;
int n, m, N, a[NUM];
int pre[NUM];
map<int, int> mp;
vector<int> pos[NUM];
struct Query
{
    int l, r;
    int id, ans;
    bool operator < (const Query & b) const
    {
        if(r == b.r) return l < b.l;
        return r < b.r;
    }
    void in(int _id)
    {
        IN(l), IN(r), id = _id;
        r = l + r - 1;
    }
} Q[NUM];
bool cmp_id(Query a, Query b)
{
    return a.id < b.id;
}
int sum[NUM];
void up(int p, int val)
{
    for(; p; p -= p & -p)
        sum[p] += val;
}
int read(int p)
{
    int res = 0;
    if(p)
        for(; p < NUM; p += p & -p)
            res += sum[p];
    return res;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int i, j;
    IN(n);
    N = 1;
    for(i = 1; i <= n; i++)
    {
        IN(a[i]);
        if(mp.find(a[i]) == mp.end())
            mp[a[i]] = N++;
        a[i] = mp[a[i]];
        if(pos[a[i]].empty())
            pre[i] = 0;
        else
            pre[i] = pos[a[i]].back();
        pos[a[i]].PB(i);
    }
    IN(m);
    for(i = 1; i <= m; i++)
    {
        Q[i].in(i);
        vector<int> &v = pos[a[Q[i].r]];
        Q[i].r = *lower_bound(v.begin(), v.end(), Q[i].l);
    }
    sort(Q + 1, Q + 1 + m);
    //O(n + m);
    for(i = 1, j = 1; j <= m && i <= n; i++)
    {
        up(i, 1);
        up(pre[i], -1);
        for(; j <= m && Q[j].r <= i; j++)
            Q[j].ans = read(Q[j].l);
    }
    sort(Q + 1, Q + 1 + m, cmp_id);
    for(int i = 1; i <= m; i++)
        printf("%d\n", Q[i].ans);
    return 0;
}
