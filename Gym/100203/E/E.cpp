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
const int NUM = 100010;
char s[110], t[110];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int c;
    IN(c);
    for(int cas = 1; cas <= c; cas++)
    {
        scanf("%s%s", s, t);
        int ans = 0;
        int len = strlen(s);
        int num1 = 0, num2 = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '?' && t[i] == '0')
            {
                ans++;
                s[i] = '0';
            }
            if(s[i] == '1') num1++;
            if(t[i] == '1') num2++;
        }
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '?')
            {
                ans++;
                if(num2 - num1 > 0) s[i] = '1', num1++;
                else s[i] = '0';
            }
        }
        if(num1 > num2)
        {
            printf("Case %d: -1\n", cas);
        }
        else
        {
            for(int i = 0; num1 < num2 && i < len; i++)
                if(s[i] == '0' && t[i] == '1')
                {
                    ans++;
                    num1++;
                    s[i] = '1';
                }
            for(int i = 0; num1 < num2 && i < len; i++)
                if(s[i] == '0' && t[i] == '0')
                {
                    ans++;
                    num1++;
                    s[i] = '1';
                }
            int cnt = 0;
            for(int i = 0; i < len; i++)
                if(s[i] != t[i])
                    cnt++;
            ans += cnt / 2;
            printf("Case %d: %d\n", cas, ans);
        }
    }
    return 0;
}
