#include <cstdio>
#define sqr(_x) ((_x)*(_x))
double a[50], b[50], c[50];
double val[50][50];
double res = 0;
int n, m;
void solve(int status)
{
	double tmp = 0;
	for(int i = 0; i < n; i++) if((1 << i) & status)
		for(int j = 0; j < n; j++) if((1 << j) & status)
			tmp += val[i][j];
	if(tmp > res) res = tmp;
}

void kSubSet(int n, int k)
{
	int x = (1 << k) - 1;
	while(x < (1 << n))
	{
		solve(x);
		int tx = x & -x, ty = tx + x;
		x = (((x ^ ty) >> 2) / tx) | ty;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	if(m == 0) { printf("%.20f\n", 0.0); return 0; }
	for(int i = 0; i < n; i++) scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			val[i][j] = sqr(a[i] - a[j]) + sqr(b[i] - b[j]) + sqr(c[i] - c[j]);
	kSubSet(n, m);
	printf("%.20f\n", res / 2);
	return 0;
}
