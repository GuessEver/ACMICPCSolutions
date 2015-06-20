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
const int NUM = 100010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n, s, f;
int get(int x)
{
	return x / 3 + x % 3;
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    scanf("%d%d%d", &n, &s, &f);
    if(s > f)
        s = n + 1 - s, f = n + 1 - f;
    int m = f - s - 1;
    if(m == 0 && s > 1 && f < n)
        puts("-1");
    else if(s == 1)
    {
        if(f == n)
        {
            printf("%d\n", get(m + 1));
        }
        else
        {
            printf("%d\n", get(m) + 1);
        }
    }
    else
    {
        if(f == n)
            printf("%d\n", get(m) + 1);
        else
            printf("%d\n", get(m - 1) + 2);
    }
    return 0;
}
