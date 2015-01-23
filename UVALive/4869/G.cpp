#include <cstdio>
#include <algorithm>
using std::max;

const int N = 250000 + 10;

int n, f[N], a[N];

int MaxSubSum()
{
	int res = a[1];
	for(int i = 1; i <= n; i++)
	{
		f[i] = max(a[i], f[i-1] + a[i]);
		res = max(res, f[i]);
	}
	return res;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) f[i] = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		printf("%d\n", MaxSubSum());
	}
	return 0;
}
