#include <cstdio>
#include <cmath>
const int N = 1000000 + 10;
int n, a[N], maxp;

int mul(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res *= x;
		x *= x; y /= 2;
	}
	return res;
}

int calc(int x)
{
	int res = 0;
	while(x)
	{
		int y = log(x) / log(2.0) + 2;
		int t = mul(2, y);
		while(t > x) { y--; t = mul(2, y); }
		x -= t; res++;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		if(x > maxp) maxp = x;
		a[x]++;
	}
	for(int i = 0; i < maxp; i++)
	{
		a[i+1] += a[i] / 2;
		a[i] %= 2;
	}
	int res = 0;
	for(int i = 0; i <= maxp; i++) res += calc(a[i]);
	printf("%d\n", res);
	return 0;
}
