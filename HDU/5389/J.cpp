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
int n;
LL mod = 258280327LL;
LL dp[NUM][10];
LL ans;
int A, B, a[NUM];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    int T;
    IN(T);
    while(T--)
    {
        IN(n), IN(A), IN(B);
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += IN(a[i]);
            if(sum >= 10)
                sum -= 9;
        }
        ans = 0;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int x;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < 10; j++)
                if(dp[i - 1][j])
                {
                    x = j + a[i];
                    if(x >= 10) x -= 9;
                    dp[i][x] += dp[i - 1][j];
                    if(dp[i][x] >= mod) dp[i][x] -= mod;
                    dp[i][j] += dp[i - 1][j];
                    if(dp[i][j] >= mod) dp[i][j] -= mod;
                }
        }
        ans = (dp[n][A] + (sum == B)) % mod;
        U(ans);
        puts("");
    }
    return 0;
}
