#include <cstdio>

int n, w, k;

int main()
{
	scanf("%d%d%d", &k, &n, &w);
	long long tot = 1ll * w * (w + 1) / 2 * k;
	long long res = tot - n;
	if(res >= 0) printf("%I64d\n", res);
	else printf("%d\n", 0);
	return 0;
}
