#include <cstdio>
#include <algorithm>

int n, a[1010];

int calc(int x, int y)
{
	if(x < y) std::swap(x, y);
	int tmp1 = x - y;
	int tmp2 = y + 9 - x + 1;
	return std::min(tmp1, tmp2);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%1d", &a[i]);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%1d", &x);
		res += calc(a[i], x);
	}
	printf("%d\n", res);
	return 0;
}
