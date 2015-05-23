#include <cstdio>
#include <cmath>

const double pi = acos(-1.0);
int n;

int main()
{
	scanf("%d", &n);
	if(n == 1) puts("1.0000000");
	else if(n == 2) puts("2.0000000");
	else{
		double alpha = 2 * pi / n;
		double beta = (pi - alpha) / 2;
		printf("%.7f\n", 2 * sin(beta) / sin(alpha) + 1.0);
	}
	return 0;
}
