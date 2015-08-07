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
LL n, m;
struct node
{
    LL i, x, ix;
} B[NUM], A[NUM];
bool operator < (node a, node b)
{
    return a.x < b.x;
}
LL sumj, sumjb, sumb;
LL sumi, sumia, suma;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    IN(n), IN(m);
    for(LL i = 1; i <= n; i++)
        A[i].ix = (A[i].i = i) * IN(A[i].x);
    sumj = 0, sumjb = 0, sumb = 0;
    for(LL i = 1; i <= m; i++)
    {
        B[i].ix = (B[i].i = i) * IN(B[i].x);
        sumj += i;
        sumjb += B[i].ix;
        sumb += B[i].x;
    }
    sort(A + 1, A + 1 + n);
    sort(B + 1, B + 1 + m);
    sumi = 0, sumia = 0, suma = 0;
    LL ans = 0;
    for(LL i = 1, j = 1; i <= n; i++)
    {
    	while(j <= m && B[j].x < A[i].x)
		{
            sumi += B[j].i;
            suma += B[j].x;
            sumia += B[j].ix;
            sumj -= B[j].i;
            sumb -= B[j].x;
            sumjb -= B[j].ix;
            j++;
		}
		ans += (j - 1) * A[i].ix - A[i].x * sumi - A[i].i * suma + sumia;
		ans -= (m - j + 1) * A[i].ix - A[i].x * sumj - A[i].i * sumb + sumjb;
    }
    U(ans);
    return 0;
}
