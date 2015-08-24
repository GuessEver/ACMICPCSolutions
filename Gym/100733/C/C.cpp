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
LL x, y;
void in()
{
	char c = getchar();
	while(c == ' ' || c == '\n') c = getchar();
	x = 0, y = 100;
	while('0' <= c && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	if(c == '.')
	{
		c = getchar();
		while('0' <= c && c <= '9')
		{
			x = x * 10 + c - '0';
			y = y * 10;
			c = getchar();
		}
	}
}
int main()
{
#ifdef ACM_TEST
//    freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	in();
	LL g = __gcd(x, y);
	cout << y / g << endl;
    return 0;
}
