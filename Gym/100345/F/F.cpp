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
#include <deque>
#include <stack>
#include <climits>
#include <bitset>
#define INF 1000000007
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
const double EPS = 1e-7, PI = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
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
//------------------------   code   ---------------------------------//
const int NUM = 100010;
vector<LL> v;
void pre()
{
    LL now = 2, k = 2, limit = 1000000000000LL;
    while(now <= limit)
    {
        v.PB(now);
        now = now + k;
        if(now >= k * k)
        {
            now++;
            k++;
        }
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#else
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
#endif
    pre();
    LL n;
    IN(n);
    vector<LL>::iterator it = lower_bound(v.begin(), v.end(), n);
    if(it  != v.end() && *it == n)
        puts("LOSE");
    else
        puts("WIN");
    return 0;
}
