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
LL dp[100][2], one[100][2], sum[100];
int tot;
LL limit  = 1000000000000000LL;
void pre()
{
    dp[0][0] = 1;
    tot = 1;
    for(int &i = tot; sum[i - 1] <= limit; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        sum[i] = sum[i - 1] + dp[i][1] * i;
        one[i][0] = one[i - 1][0] + one[i - 1][1];
        one[i][1] = one[i - 1][0] + dp[i - 1][0];
    }
}
LL n, ans, m;
LL solve(int bit, LL cnt)
{
    if(cnt <= 0) return 0;
    if(cnt <= m) return 1;
    if(m * dp[bit][0] <= cnt)
    {
        cnt -= m * dp[bit][0];
        ans += one[bit][0];
        if(cnt == 0) return dp[bit][0];
        LL res = solve(bit - 2, cnt);
        ans += res;
        cnt = cnt % m;
        if(cnt && m - cnt >= bit) ans--;
        return res + dp[bit][0];
    }
    else
        return solve(bit - 1, cnt);
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("fibonacci.in", "r", stdin);
    freopen("fibonacci.out", "w", stdout);
#endif
    pre();
    while(~scanf("%I64d", &n))
    {
        for(int i = tot - 1; i >= 0; i--)
            if(n >= sum[i])
            {
                n -= sum[i];
                ans = one[i + 1][0];
                if(n == 0) break;
                else m = i + 1;
                LL num = solve(i - 1, n);
                ans += num;
                break;
            }
        U(ans);
        puts("");
    }
    return 0;
}
