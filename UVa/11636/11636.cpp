#include <cstdio>
#include <cmath>

int n;

void solve()
{
	int res = ceil(log2(1.0 * n));
	printf("%d\n", res);
}

int main()
{
	freopen("11636.in", "r", stdin);
	freopen("11636.out", "w", stdout);
	int cases = 0;
	while(scanf("%d", &n) == 1 && n>0) 
	{
		printf("Case %d: ", ++cases);
		solve();
	}
	return 0;
}
