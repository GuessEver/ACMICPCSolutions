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
int ans1, ans2, n;
int a[1010], b[1010], c[1010];
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	scanf("%d", &n);
	ans1 = ans2 = 0;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(i = 0; i < n; i++)
	{
		int u = abs(b[i] - c[i]), v = abs(a[i] - c[i]);
		if(u > v)
			ans1++;
		else if(u < v)
			ans2++;
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
