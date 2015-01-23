#include <cstdio>

int main()
{
	double a = 0;
	double k = 1;
	for(int i = 1; i <= 10000; i++)
	{
		a += i * k;
		k *= (5.0 / 6.0);
	}
	a /= 6.0;
	printf("%.8lf\n", a);
}
