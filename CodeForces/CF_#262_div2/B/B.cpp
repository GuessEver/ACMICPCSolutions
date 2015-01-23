#include <cstdio>
#include <algorithm>

long long ans[99999];
int len;

long long calc(int a, int b, int c, int s)
{
	long long res = 1;
	for(int i = 1; i <= a; i++) res *= s;
	return res * b + c;
}

bool check(long long x, int s)
{
	int cc = 0;
	while(x)
	{
		cc += x % 10;
		x /= 10;
	}
	return cc == s;
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for(int s = 1; s <= 81; s++)
	{
		long long x = calc(a, b, c, s);
		if(x >= 1000000000) continue;
		if(check(x, s)) ans[len++] = x;
	}
	std::sort(ans, ans+len);
	printf("%d\n", len);
	if(len == 0) return 0;
	for(int i = 0; i < len-1; i++) printf("%I64d ", ans[i]);
	printf("%I64d\n", ans[len-1]);
	return 0;
}
