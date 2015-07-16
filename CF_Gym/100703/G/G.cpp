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
#include <climits>
#define INF 1000000007
#define MP make_pair
const int NUM = 1100;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n, k, c[NUM];
bool dp[NUM][NUM];
int pre[NUM][NUM];
int ansi, ansn, ans[NUM];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    memset(pre, -1, sizeof(pre));
    dp[0][0] = true;
    bool flag = true;
    for(i = 1; flag && i <= n; i++)
    {
        flag = false;
        for(j = 0; j <= k; j++)
            if(dp[i - 1][j])
            {
                if(j + c[i] <= k)
                {
                    flag = true;
                    ansi = i;
                    ansn = j + c[i];
                    pre[i][j + c[i]] = j;
                    dp[i][j + c[i]] = true;
                }
                if(j - c[i] >= 0)
                {
                    flag = true;
                    ansi = i;
                    ansn = j - c[i];
                    pre[i][j - c[i]] = j;
                    dp[i][j - c[i]] = true;
                }
            }
    }
    for(i = ansi, j = ansn; i > 0; i--)
    {
        if(pre[i][j] <= j)
            ans[i] = 1;
        else
            ans[i] = -1;
        j = pre[i][j];
    }
    printf("%d\n", ansi);
    for(i = 1; i <= ansi; i++)
        printf("%c", ans[i] == 1 ? '+' : '-');
    return 0;
}
