#include <cstdio>
#include <cmath>
#include <algorithm>
using std::max;

int calc(int p, int t)
{
	return max(3 * p / 10, p - p / 250 * t);
}

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int m = calc(a, c);
	int v = calc(b, d);
	if(m == v) puts("Tie");
	else if(m > v) puts("Misha");
	else puts("Vasya");
	return 0;
}
