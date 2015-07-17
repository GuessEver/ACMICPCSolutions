#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, x, c[N];

int main()
{
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	std::sort(c+1, c+1+n);
	long long ans = 0;
	for(int i = 1; i <= n; i++, x = std::max(x-1, 1))
		ans += 1ll * c[i] * x;
	printf("%I64d\n", ans);
	return 0;
}
