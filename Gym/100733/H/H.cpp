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
const int NUM = 27;
int cost[NUM][NUM];
char s[1000000 + 10];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            scanf("%d", &cost[i][j]);
        }
        cost[i][i] = 0;
    }
    int i, j, k;
    for(k = 0; k < 26; k++)
        for(i = 0; i < 26; i++)
            for(j = 0; j < 26; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    LL ans = 0;
    scanf("%s", s);
    for(int i = 0, j = strlen(s) - 1; i < j; ++i, --j)
    {
        if(s[i] == s[j]) continue;
        LL mincost = LONG_LONG_MAX;
        for(int k = 0; k < 26; ++k)
        {
            mincost = min(mincost, 1LL * cost[s[i] - 'a'][k] + cost[s[j] - 'a'][k]);
        }
        ans += mincost;
    }
    printf("%lld\n", ans);
    return 0;
}
