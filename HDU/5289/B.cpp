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
#include <deque>
#include <ctime>
#include <climits>
#define INF 1000000007
#define MP make_pair
const double EPS = 1e-10, PI = acos(-1.0);
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
int n, k, a[NUM];
struct node
{
    int i, val;
};
deque<node> demx, demi;
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//    freopen("in.txt", "w", stdout);
#endif
    LL i, j;
    int T;
    IN(T);
    while(T--)
    {
        IN(n), IN(k);
        for(i = 0; i < n; i++)
            IN(a[i]);
        a[n] = INF;
        demx.clear(); demi.clear();
        LL ans = 0;
        for(i = j = 0; i < n; i++)
        {
            while(j < n)
            {
                while(!demx.empty() && demx.back().val < a[j]) demx.pop_back();
                while(!demi.empty() && demi.back().val > a[j]) demi.pop_back();
                demx.push_back((node) {j, a[j]});
                demi.push_back((node) {j, a[j]});
                if(demx.front().val - demi.front().val >= k) break;
                j++;
            }
            ans += j - i ;
            while(!demx.empty() && demx.front().i <= i) demx.pop_front();
            while(!demi.empty() && demi.front().i <= i) demi.pop_front();
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
