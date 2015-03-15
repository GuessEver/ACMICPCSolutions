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
const int NUM = 100010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
LL n, sn;

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
        scanf("%I64d", &n);
        sn = (LL)sqrt((double)n);
        LL S = 0;
        for(LL i = 1; i <= sn; i++)
        {
            S += (n/i - n/(i + 1))*i;
        }
        for(LL i = n/(sn + 1); i > 0; i--)
            S += n/i;
        printf("%I64d\n", S%(1000000LL));
    }
    return 0;
}
