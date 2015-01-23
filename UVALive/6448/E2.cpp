#include <cstdio>
#include <cmath>

void solve(double R, double B, double M)
{
	if(fabs(R-1) < 1e-6)
	{
		printf("%d\n", (int)(B / M + 0.999999));
	}
	double p = M / (R - 1);
	// An = (A1 - p) * R^(n-1) + p >= 0
	double A1 = B;
	//if(A1 <= 0)
	//{
///		printf("1\n");
//		return;
//	}
	//if(A1 >= p)
//	{
//		printf("impossible\n");
//		return;
//	}
	if(B * R - M >= B)
	{
		printf("impossible\n");
		return;

	}
	double Rn = p / (p - A1);
//	double low = 0, high = 1000000, mid;
//	while(fabs(high-low) > 1e-6)
//	{
//		mid = (low + high) / 2;
//		if(pow(R, mid) > Rn) high = mid;
//		else low = mid;
//	}
//	printf("%d\n", (int)(low+0.999999)-1);
	for(int i = 1; ; i++)
	{
		if(pow(R, i) >= Rn-1e-6)
		{
			printf("%d\n", i);
			break;
		}
	}
}

int main()
{
	freopen("E.in", "r", stdin);
	int T; scanf("%d", &T);
	while(T--)
	{
		double R, B, M;
		scanf("%lf%lf%lf", &R, &B, &M);
		R /= 100;
		R += 1;
		solve(R, B, M);
	}
	return 0;
}
