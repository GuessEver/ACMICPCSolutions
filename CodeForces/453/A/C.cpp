#include <cstdio>
#include <cmath>

int n, m;

double calc(int x)
{
	double tmp = pow(1.0 * x / m, n) - pow(1.0 * (x-1) / m, n);
	return 1.0 * x * tmp;
}

int main()
{
	scanf("%d%d", &m, &n);
	double ans = 0.0;
	for(int i = 1; i <= m; i++) ans += calc(i);
	printf("%.12lf\n", ans);
	return 0;
}
