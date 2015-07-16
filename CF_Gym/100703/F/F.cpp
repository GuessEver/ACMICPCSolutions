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
const int NUM = 405;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int m, n, q[NUM], p[NUM], dp[NUM][NUM][NUM];

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j, k, u, v;
    scanf("%d%d", &m, &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
            for(k = 0; k <= m; k++)
                dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    u = (m + 1) / 2, v = m / 2;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < i; j++)
            for(k = 0; k < i; k++)
                if(j + k < i)
                {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i - 1][j][k] + q[i]);
                    dp[i][j][k + 1] = min(dp[i][j][k + 1], dp[i - 1][j][k] + p[i]);
                }
    }
    printf("%d\n", min(dp[n][u][v], dp[n][v][u]));
    return 0;
}
