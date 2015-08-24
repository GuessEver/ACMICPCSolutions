#include <cstdio>
#include <cmath>
const double PI = acos(-1.0);
int n, a, b;
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	double alpha = PI / n;
	double S = 1.0 * n * a * b * sin(alpha);
	printf("%.9f\n", S);
	return 0;
}
