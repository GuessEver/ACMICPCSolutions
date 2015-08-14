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
const int NUM = 1000010;

int n, k, d[NUM];
multiset<int> st;
multiset<int> :: iterator it;
int ans;

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int l;
    IN(n), IN(k);
    for(int i = 0; i < n; i++) IN(d[i]);
    for(int i = 0; i < k; i++)
        st.insert(IN(l));
    ans = n;
    sort(d, d + n);
    for(int i = n - 1; i >= 0; i--)
    {
        int u = d[i];
        if(st.empty())
        {
            puts("NIE");
            return 0;
        }
        it = st.end();
        it--;
        if(5 * u <= *(it))
        {

            st.erase(it);
        }
        else
        {
            ans++;
            it = st.lower_bound(3 * u);
            if(it != st.end())
                st.erase(it);
            else
            {
                puts("NIE");
                return 0;
            }
            it = st.lower_bound(2 * u);
            if(it != st.end())
                st.erase(it);
            else
            {
                puts("NIE");
                return 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
