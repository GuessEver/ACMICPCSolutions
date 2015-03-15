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
#define INF 1000000007
#define MP make_pair
const int NUM = 1000010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
LL n, p, a[NUM], ma[NUM];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//  freopen("in.txt", "w", stdout);
#endif
    int i, j;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d", &n, &p);
        for(i = 0; i < n; i++)
            scanf("%I64d", a + i);
        ma[n - 1] = a[n - 1];
        for(i = n - 2; i >= 0; i--)
            ma[i] = max(a[i], ma[i + 1]);
        LL ans = 0;
        for(i = 0; i < n - 1; i++)
        {
            ans = max(ans, (p/a[i])*(ma[i + 1] - a[i]));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
