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
LL n, k;
LL a[NUM];
LL solve(LL x)
{
    LL m = n - x - 1;
    LL i, j = 1;
    while(m < 62LL && m >= 0 && k >= (1LL << m))
    {
        k -= (1LL << m);
        m--;
        j++;
    }
    for(i = j - 1; i > 0; i--)
        swap(a[x + i], a[x + i - 1]);
    return x + j;
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
#endif
    LL i, j;
    while(~scanf("%I64d%I64d", &n, &k) && n + k)
    {
        for(i = 1; i <= n; i++)
            a[i] = i;
        i = 1;
        k--;
        while(i < n)
        {
            i = solve(i);
        }
        for(i = 1; i <= n; i++)
            printf("%I64d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}
