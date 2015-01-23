#include <cstdio>

int main()
{
	freopen("10970.in", "r", stdin);
	//freopen("10970.out", "w", stdout);
	long long n,m;
	while(scanf("%lld%lld", &n, &m) == 2)
		printf("%lld\n", n*m-1);
	return 0;
}
