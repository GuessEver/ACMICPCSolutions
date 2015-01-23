#include <cstdio>
#include <cmath>
#define sqr(_x) ((_x) * (_x))

const double eps = 1e-6;

double h1, h2, d1, d2, a, b;

bool solve()
{
	if(h1 / b - d2 * d2 > 0) return 0;
	// one
	double y1 = h1 - a * sqr(d2);
	double y2 = h1 - a * sqr(d1);
	if(y2 >= h2 - eps && fabs(y1) <= eps) return 1;

	//two
	double aa = (a + b);
	double bb = -2 * b * d2;
	double cc = b * sqr(d2) -h1;
	double delta = sqr(bb) - 4 * aa * cc;
	if(delta < 0) return 0;
	double xx[2];
   	xx[0] = (-bb + sqrt(delta)) / (2 * aa);
	xx[1] = (-bb - sqrt(delta)) / (2 * aa);
	if(xx[0] < 0 && xx[1] < 0) return 0;
	for(int i = 0; i < 2; i++)
	{
		if(xx[i] >= d1)
		{
			double yy = h1 - a * sqr(d1);
			if(yy >= h2) return 1;
		}
		else{
			double y1 = h1 - a * sqr(xx[i]);
			double yy = y1 - b * sqr(xx[i] - d1);
			if(yy >= h2) return 1;
		}
	}
	return 0;
}

int main()
{
	while(scanf("%lf%lf%lf%lf%lf%lf", &h1, &h2, &d1, &d2, &a, &b) == 6)
	{
		if(solve()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
