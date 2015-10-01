#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 100 + 10;
int n, m, L;
double p[N], t[N]; int v[N];

double C(int n, int m)
{
	double res = 1.0;
	for(int i = 1; i <= m; i++) res *= (0.0 + n--) / i;
	return res;
}
double mul(double x, int y)
{
	if(y == 0) return 1.0;
	if(y & 1) return mul(x * x, y / 2) * x;
	return mul(x * x, y / 2);
}
double time[N][N], pp[N][N], sump[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &L);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf%lf%d", &p[i], &t[i], &v[i]);
		p[i] /= 100.0;
	}
	for(int i = 1; i <= n; i++)
		for(int k = 0; k <= m; k++)
		{
			time[i][k] = fabs((0.0 + L) / v[i]) + k * t[i];
			sump[i][k] = pp[i][k] = C(m, k) * mul(p[i], k) * mul(1 - p[i], m - k);
			if(k) sump[i][k] += sump[i][k-1];
			//printf("%d %d : %.4f %.4f %.4f\n", i, k, time[i][k], pp[i][k], sump[i][k]);
		}
	for(int i = 1; i <= n; i++)
	{
		if(v[i] == 0) printf("%.8f\n", 0.0);
		else {
			double res = 0.0;
			for(int k = 0; k <= m; k++)
			{
				double resp = pp[i][k];
				for(int j = 1; j <= n; j++) if(i != j)
				{
					int pos = std::upper_bound(time[j], time[j]+m+1, time[i][k]) - time[j];
					double tmp = 1.0 - (pos == 0 ? 0.0 : sump[j][pos-1]);
					resp *= tmp;
				}
				res += resp;
				//printf("i = %d, k = %d, resp = %.5f\n", i, k, resp);
			}
			printf("%.8f\n", res);
		}
	}
	return 0;
}
