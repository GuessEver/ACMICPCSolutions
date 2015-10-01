#include <cstdio>
#include <cmath>
int k, L, R;
double p, e, t;
double res = 0.0;
const double EPS = 1e-10;

int dcmp(double a, double b)
{
	double x = a - b;
	if(fabs(x) < EPS) return 0;
	return x < 0 ? -1 : 1;
}
void solve(int x, double L, double R, double pp)
{
	//printf("%d %.4f %.4f %.4f: %.4f\n", x, L, R, pp, res);
	if(dcmp(R, (t - e)) < 0) return;
	if(dcmp(L, (t + e)) > 0) return;
	if(dcmp(R, (t + e)) <= 0 && dcmp(L, (t - e)) >= 0)
	{
		//printf("!! %d %.4f %.4f %.4f: %.4f\n", x, L, R, pp, res);
		res += pp;
		return;
	}
	double mid = (L + R) / 2;
	if(x == k)
	{
		//printf("!! %d %.4f %.4f [%.4f] %.4f: %.4f\n", x, L, R, mid, pp, res);
		if(dcmp(mid, (t - e)) >= 0 && dcmp(mid, (t + e)) <= 0)
			res += pp;
	}
	else {
		if(dcmp(t, mid) >= 0)
		{
			solve(x + 1, mid, R, pp * (1 - p));
			solve(x + 1, L, mid, pp * p);
		}
		else {
			solve(x + 1, mid, R, pp * p);
			solve(x + 1, L, mid, pp * (1 - p));
		}
	}
}

int main()
{
	scanf("%d%d%d", &k, &L, &R);
	scanf("%lf%lf%lf", &p, &e, &t);
	solve(0, L, R, 1.0);
	printf("%.6f\n", res);
	return 0;
}
