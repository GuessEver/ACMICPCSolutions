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
#define INF 1000000007
#define MP make_pair
const int NUM = 100010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
double a, b, c, x, y, z;

int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	scanf("%lf%lf%lf", &x, &y, &z);
	scanf("%lf%lf%lf", &a, &b, &c);
	double ans;
	if(a < 0)
	{
		a = x - a, b = y - b, c = z - c;
	}
	else
	{
		a -= x, b -= y, c -= z;
	}
	double d = b*b - 4.0 * a * c;
	if(d < 0)
		ans = 0;
	else
	{
		d = sqrt(d);
		double x1 = (-b + d)/(2.0 * a), x2 = (-b - d)/(2.0 * a);
		ans = (a*x1*x1*x1/3.0 + b*x1*x1/2.0 + c*x1) - (a*x2*x2*x2/3.0 + b*x2*x2/2.0 + c*x2);
	}
	printf("%.3f", abs(ans));
	return 0;
}

