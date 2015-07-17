#include <cstdio>
#include <cmath>

double S(int x)
{
	return 1.0 * x * x;
}

int main()
{
	int r, x, y, xx, yy;
	scanf("%d%d%d%d%d", &r, &x, &y, &xx, &yy);
	double dis = sqrt(S(x-xx) + S(y-yy));
	printf("%.0lf\n", ceil(dis/(r*2)));
	return 0;
}
