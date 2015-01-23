#include <cstdio>

int main()
{
	double ans = 0;
	double k = 1;
	for(int i = 1; i <= 100; i++)
	{
		ans += 1.0 / 3.0 * k * i;
		k *= 2.0 / 3.0;
	}
	printf("%.5lf\n", ans);
}
