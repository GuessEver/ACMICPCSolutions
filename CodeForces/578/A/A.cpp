#include <cstdio>

int main()
{
	int a, b; scanf("%d%d", &a, &b);
	if(a < b) puts("-1");
	else {
		double A = (a + b) / (2 * b);
		printf("%.10f\n", (a + b) / 2.0 / A);
	}
	return 0;
}
