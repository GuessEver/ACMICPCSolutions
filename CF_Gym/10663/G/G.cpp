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
LL minute = 1000000, hour = minute * minute, day = hour * 12LL;
LL in()
{
    LL h, m, s;
    scanf("%I64d%I64d%I64d", &h, &m, &s);
    return h * hour + m * minute + s;
}
inline LL go(LL t1, LL t2)
{
    if(t1 <= t2) return t2 - t1;
    return t2 + day - t1;
}
LL mclock[NUM], n;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        mclock[i] = in();
    sort(mclock, mclock + n);
    if(mclock[0] == mclock[n - 1])
	{
		puts("0 0 0");
		return 0;
	}
    LL ans, sum = 0, t, m;
    for(i = 0; i < n - 1; i++)
    {
        sum += mclock[n - 1] - mclock[i];
    }
    ans = sum;
    for(i = 0; i < n - 1; )
    {
        m = 0;
        j = i;
        while(j < n && mclock[j] == mclock[i]) j++, m++;
        if(i == 0)
            t = go(mclock[n - 1], mclock[i]);
        else
            t = go(mclock[i - 1] , mclock[i]);
        sum = sum - m * (day - t) + t * (n - m);
        ans = min(ans, sum);
        i = j;
    }
    LL ah = ans / hour, am , as;
    am = (ans % hour) / minute;
    as = ans % minute;
    cout << ah << ' ' << am << ' ' << as << endl;
    return 0;
}
