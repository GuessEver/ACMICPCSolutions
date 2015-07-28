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
const int NUM = 50010;
int n, m, q;
int ans[NUM];
struct traval
{
	int x, y;
	void in(){IN(x), IN(y);}
}t[NUM], now[NUM];
bool cmpx(traval a, traval b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
bool cmpy(traval a, traval b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
	//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	while(~scanf("%d%d%d", &n, &m, &q))
	{
		for(i = 0; i < m; i++)
			t[i].in();
		for(i = 0; i < q; i++)
		{
			IN(now[i].x);
			now[i].y = i;
		}
		sort(t, t + m, cmpx);
		sort(now, now + q, cmpx);
		int min1 = INF, min2 = INF;
		for(i = q - 1, j = m - 1; i >= 0; i--)
		{
			while(j >= 0 && t[j].x >= now[i].x)
			{
				if(t[j].y <= min1)
				{
					min2 = min1;
					min1 = t[j].y;
				}
				else if(t[j].y <= min2)
				{
					min2 = t[j].y;
				}
				j--;
			}
			if(min1 >= now[i].x || min2 >= now[i].x) ans[now[i].y] = 0;
			else ans[now[i].y] = now[i].x - min2;
		}
		for(i = 0; i < q; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
