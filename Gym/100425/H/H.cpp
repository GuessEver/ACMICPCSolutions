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

int main()
{
#ifdef ACM_TEST
    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    if(p == 100)
	{
		puts("1");
		printf("0 1");
		for(int i = 2; i < n; i++)
			printf(" 0");
		return 0;
	}
    else if(p >= 50)
    {
        puts("0");
        return 0;
    }
    int g = __gcd(50 - p, 50);
    int a = (50 - p) / g, b = 50 / g;
    vector<int> ans;
    ans.push_back(a);
    b -= a;
    for(int i = 1; i < n; i++)
	{
		if(b > k)
		{
			ans.push_back(k);
			b -= k;
		}
		else
		{
			ans.push_back(b);
			b = 0;
		}
	}
	if(b > 0 || a > k)
	{
		puts("0");
	}
	else
	{
		puts("1");
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i]);
	}
    return 0;
}
