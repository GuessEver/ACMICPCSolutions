#include <cstdio>
#include <algorithm>
using std::min;

int main()
{
	long long l, p, v;
	long long cas = 0;
	while(scanf("%lld%lld%lld", &l, &p, &v) == 3 && (l || p || v))
	{
		cas++;
		long long ans = v / p * l;
		v = v - v / p * p;
		ans += min(v, l);
		printf("Case %lld: %lld\n", cas, ans);
	}
	return 0;
}
