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
//------------------------   code   ---------------------------------//
const int NUM = 20000 * 2 + 10;
int sa[NUM];
int rk[NUM], height[NUM], sv[NUM], sn[NUM];
void da(char r[], int n, int m)
{
    int i, j, p, *x = rk, *y = height;
    for(i = 0; i < m; i++) sn[i] = 0;
    for(i = 0; i < n; i++) sn[x[i] = r[i]]++;
    for(i = 1; i < m; i++) sn[i] += sn[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--sn[x[i]]] = i;
    for(j = p = 1; p < n; j <<= 1, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) sv[i] = x[y[i]];
        for(i = 0; i < m; i++) sn[i] = 0;
        for(i = 0; i < n; i++) sn[sv[i]]++;
        for(i = 1; i < m; i++) sn[i] += sn[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--sn[sv[i]]] = y[i];
        for(swap(x, y), x[sa[0]] = 0, i = 1, p = 1; i < n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + j] == y[sa[i - 1] + j]) ? p - 1 : p++;
    }
}
void cal_height(char *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 0; i < n; i++)rk[sa[i]] = i;
    for(i = 0; i < n; height[rk[i++]] = k)
        for(k ? k-- : 0, j = sa[rk[i] - 1]; r[i + k] == r[j + k]; k++);
}
char s[NUM], ans1[NUM], ans2[NUM];
int res1, res2;
int n;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%s", &n, s);
        for(int i = 0; i < n; ++i) s[i + n] = s[i];
        s[n + n] = 0;
        da(s, n + n + 1, 'z' + 1);
        cal_height(s, sa, n + n + 1);
        int k = 0;
        for(int i = n + n; i >= 0; --i) if(sa[i] < n) {k = i; break;}
        res1 = sa[k];
        while(height[k] >= n) res1 = min(res1, sa[--k]);
        for(int i = 0; i < n; ++i) ans1[i] = s[res1 + i];
        ans1[n] = 0;
        //
        reverse(s, s + n + n);
        da(s, n + n + 1, 'z' + 1);
        cal_height(s, sa, n + n + 1);
//        for(int i = 0; i <= n + n; ++i) printf("%d %s %d\n", sa[i], s + sa[i], height[i]);
        k = 0;
        for(int i = n + n; i >= 0; --i) if(sa[i] < n) {k = i; break;}
        res2 = sa[k];
        while(height[k--] >= n)if(sa[k] < n) res2 = max(res2, sa[k]);
        for(int i = 0; i < n; ++i) ans2[i] = s[res2 + i];
        ans2[n] = 0;
        k = strcmp(ans1, ans2);
        ++res1, res2 = n - res2;
        if(k > 0) printf("%d 0\n", res1);
        else if(k < 0) printf("%d 1\n", res2);
        else
        {
            if(res1 <= res2) printf("%d 0\n", res1);
            else printf("%d 1\n", res2);
        }
    }
    return 0;
}
