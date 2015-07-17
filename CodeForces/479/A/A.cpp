#include <cstdio>
#include <algorithm>
using std::max;

int solve(int a, int b, int c)
{
	int res = a + b + c;
	
	res = max(res, a + b * c);
	res = max(res, (a + b) * c);
	
	res = max(res, a * b + c);
	res = max(res, a * (b + c));
	
	res = max(res, a * b * c);
	
	return res;
}

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int ans = solve(a, b, c);
	printf("%d\n", ans);
	return 0;
}
