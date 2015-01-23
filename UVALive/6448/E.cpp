#include <cstdio>
#include <cmath>

double eee = 0.00000001;

void solve(double R, double B, double M)
{
	if(B + round(B * R * 100 + eee) / 100 <= 1e-6)
	{
		printf("0\n");
		return;
	}
	int i;
	for(i = 1; i <= 1200; i++)
	{
		double I = round(B * R * 100 + eee) / 100;
		B = B + I - M;
		if(B < 1e-6) break;
	}
	if(i <= 1200) printf("%d\n", i);
	else printf("impossible\n");
}

int main()
{
	//freopen("E.in", "r", stdin);
	int T; scanf("%d", &T);
	while(T--)
	{
		double R, B, M;
		scanf("%lf%lf%lf", &R, &B, &M);
		//printf("R = %.3lf\n", R);
		R /= 100;
		solve(R, B, M);
	}
	return 0;
}
