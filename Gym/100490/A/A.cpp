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
const double EPS = 1e-9, PI = acos(-1.0);
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
const int NUM = 200010;
int n;
struct node
{
    int l, r;
    double val;
};
vector<node> v;
vector<node> t;
inline node deal(int l, int r)
{
    node tmp;
    tmp.l = v[l].l, tmp.r = v[r - 1].r;
    double sum = 0.0;
    for(int i = l; i < r; i++)
        sum += v[i].val * (double)(v[i].r - v[i].l + 1);
    tmp.val = sum / (double)(tmp.r - tmp.l + 1);
    return tmp;
}

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("approximation.in", "r", stdin);
    freopen("approximation.out", "w", stdout);
#endif
    IN(n);
    int i;
    node x;
    for(i = 1; i <= n; i++)
    {
        IN(x.val);
        x.l = x.r = i;
        v.PB(x);
    }
    while(true)
    {
        t.clear();
        for(int i = 0, j = 0; i < (int)v.size(); i = j)
        {
            j = i + 1;
            while(j < (int)v.size() && v[j].val <= v[j - 1].val) j++;
            if(i + 1 == j)
                t.PB(v[i]);
            else
                t.PB(deal(i, j));
        }
        if(t.size() == v.size())
        {
            for(int i = 0; i < (int)v.size(); i++)
            {
                for(int j = v[i].l; j <= v[i].r; j++)
                    printf("%.10f ", v[i].val);
            }
            return 0;
        }
        v = t;
    }
    return 0;
}
