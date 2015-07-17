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
int n, res;
char s[110];
void solve(int pos)
{
	int i, j;
	int sum1 = 0, sum2 = 0, num1 = 0, num2 = 0, num3 = 0;
	for(i = 0; i < pos; i++)
		if(s[i] == 'F')
		{
			num1++;
			sum1 += pos - 1 - i;
		}
		else if(s[i] == 'N')
			num3++;
	for(i = pos; i < n; i++)
		if(s[i] == 'A')
	{
		num2++;
		sum2 += i - pos;
	}
	if(num1 + num3 < num2)
		return ;
	res = min(res, sum1 + sum2 + max(num1, num2));
}
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	scanf("%d%s", &n, s);
	res = INF;
	for(i = 1; i < n; i++)
		solve(i);
	printf("%d\n", res);
	return 0;
}
