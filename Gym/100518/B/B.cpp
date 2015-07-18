#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const int N = 5000 + 10;
const double eps = 1e-9;

int n, a[N], b[N], c[N], d[N];
int A[N], B[N], C[N], D[N];
double dp[N];

int sign(double e)
{
	if(fabs(e) < eps) return 0;
	return e > 0 ? 1 : -1;
}

inline double calc(int A, int B, int C, int D)
{
	if(A + C == 0) return std::min(B, D);
	double k1 = (0.0 + C + D - B) / (A + C);
	if(sign(k1) >= 0 && sign(k1 - 1) <= 0) return A * k1 + B;
	return std::min(A + B, C + D);
}

double solve1()
{
	return calc(A[n], B[n], C[n], D[n]);
}

double solve2()
{
	double res = 0.0;
	for(int i = 1; i <= n; i++)
		res += calc(a[i], b[i], c[i], d[i]);
	return res;
}

double solve3()
{
	for(int i = 0; i <= n + 2; i++) dp[i] = 1e20;
	dp[0] = 0.0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			dp[i] = std::min(dp[i], dp[j] + calc(A[i] - A[j], B[i] - B[j], C[i] - C[j], D[i] - D[j]));
	return dp[n];
}

double solve4()
{
	for(int i = 0; i <= n + 2; i++) dp[i] = 0.0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			dp[i] = std::max(dp[i], dp[j] + calc(A[i] - A[j], B[i] - B[j], C[i] - C[j], D[i] - D[j]));
	return dp[n];
}

int main()
{
	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		A[i] = A[i-1] + a[i];
		B[i] = B[i-1] + b[i];
		C[i] = C[i-1] + c[i];
		D[i] = D[i-1] + d[i];
	}
	printf("%.10f\n", solve1());
	printf("%.10f\n", solve2());
	printf("%.10f\n", solve3());
	printf("%.10f\n", solve4());
	return 0;
}
