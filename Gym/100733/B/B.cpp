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
struct node
{
    string nickname, gangname;
    int num[260];
    int cnt[260];
} a[110];
int k, n, m;
char s[110];
int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    IN(k);
    for(int i = 1; i <= k; ++i)
    {
        scanf("%s", s);
        a[i].nickname = s;
        for(int j = 0; s[j]; j++)
            ++a[i].num[s[j]];
            scanf("%s", s);
        a[i].gangname = s;
        for(int j = 0; s[j]; ++j)
            ++a[i].num[s[j]];
    }
    int maxnum = -1, id = 0;
    for(int i = 1; i <= k; ++i)
    {
        scanf("%d%d", &n, &m);
        for(int j = 0; j < n; ++j)
        {
            scanf("%s", s);
            for(int l = 0; l < m; ++l)
                ++a[i].cnt[s[l]];
        }
        int num = INF;
        for(int j = 0; j < 260; ++j)
            if(a[i].num[j])
            {
                num = min(num, a[i].cnt[j] / a[i].num[j]);
            }
		if(num > maxnum)
		{
			maxnum = num;
			id = i;
		}
    }
    printf("%s %s\n", a[id].nickname.data(), a[id].gangname.data());
    return 0;
}
