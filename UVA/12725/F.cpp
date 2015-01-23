#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d: ", cas);
		double a, b;
		int c, d;
		scanf("%lf%lf%d%d", &a, &b, &c, &d);
		double ans = b * (c + d) - a * c;
		ans /= d;
		if(ans > 10 || ans < 0) printf("Impossible\n");
		else printf("%.2lf\n", ans);
	}
	return 0;
}
