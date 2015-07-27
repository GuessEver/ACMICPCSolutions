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
const int NUM = 200010;
int n, a[NUM], m;
int pre[NUM], nxt[NUM];
int bsz;
int pos[NUM];
struct node
{
    int l, r;
    int ans, id;
} q[NUM];
map<int, vector<int> > v;
map<int, int> mp;
map<int, int> :: iterator it;

bool cmp_lr(node a, node b)
{
    if(pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}

bool cmp_id(node a, node b) {return a.id < b.id;} //输出答案用
void init()
{
    bsz = (int)sqrt(n);//分块
    for(int i = 1; i <= n; i++)
        pos[i] = i / bsz;
}
void getPre_and_nxt()
{
    //pre
    mp.clear();
    for(int i = 1; i <= n; i++)
    {
    	v[a[i]].PB(i);
        it = mp.find(a[i]);
        if(it == mp.end())
        {
            pre[i] = -1;
            mp[a[i]] = i;
        }
        else
        {
            pre[i] = it->SE;
            it->SE = i;
        }
    }
    //nxt
    mp.clear();
    for(int i = n; i >= 1; i--)
    {
        it = mp.find(a[i]);
        if(it == mp.end())
        {
            nxt[i] = n + n;
            mp[a[i]] = i;
        }
        else
        {
            nxt[i] = it->SE;
            it->SE = i;
        }
    }
    mp.clear();
}
void input()
{
    IN(n);
    for(int i = 1; i <= n; i++)
    {
        IN(a[i]);
    }
    IN(m);
    for(int i = 1; i <= m; i++)
    {
        IN(q[i].l), IN(q[i].r);
    }
}
void input2()
{
	srand(time(0));
	n = 200000;
	for(int i = 1; i <= n; i++)a[i] = 1;
	//a[i] = 1.0*rand() / RAND_MAX * 2e9 - 1e9;
	m = 200000;
	for(int i = 1; i <= m; i++)
    {
        q[i].l = rand() % n + 1;
        q[i].r = rand() % (n + 1 - q[i].l);
    }
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
    int i;
    input();
    init();
    getPre_and_nxt();
    for(i = 1; i <= m; i++)
    {
        q[i].r += q[i].l - 1;
        q[i].id = i;
        vector<int> &vv = v[a[q[i].r]];
        q[i].r = *lower_bound(vv.begin(), vv.end(), q[i].l);
        //cout << q[i].r << endl;
    }
    sort(q + 1, q + 1 + m, cmp_lr);
    int l = 0, r = 0;
    int ans = 0;
    for(i = 1; i <= m; i++)
    {
        if(l > q[i].l)
        {
            for(l--; l >= q[i].l; l--)
            {
                ans++;
                if(nxt[l] <= r) ans--;
            }
            l++;
        }
        if(r < q[i].r)
        {
            for(r++; r <= q[i].r; r++)
            {
                if(pre[r] < l) ans++;
            }
            r--;
        }
        if(l < q[i].l)
        {
            for(; l < q[i].l; l++)
            {
                ans--;
                if(nxt[l] <= r) ans++;
            }
        }
        if(r > q[i].r)
        {
            for(; r > q[i].r; r--)
            {
                if(pre[r] < l) ans--;
            }
        }
        q[i].ans = ans;
    }
    sort(q + 1, q + m + 1, cmp_id);
    for(i = 1; i <= m; i++)
        printf("%d\n", q[i].ans);
    return 0;
}
