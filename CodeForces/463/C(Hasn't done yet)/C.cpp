#include <cstdio>

const int N = 2000 + 10;

int n;
long long sum1[N*2], sum2[N*2];
long long a[N][N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			scanf("%lld", &a[i][j]);
			sum1[i+j] += a[i][j];
			sum2[i-j+N] += a[i][j];
		}
	// sum1[ 2 ... 2 * n]
	// sum2[ 1-n+N ... n-1+N]
	int k1 = -1, k2 = -1;
	for(int i = 2; i <= 2 * n; i++)
		if(k1 == -1 || sum1[i] > sum1[k1]) k1 = i;
	for(int i = 2; i <= 2 * n; i++)
		if(i != k1 && (k2 == -1 || sum1[i] > sum1[k2])) k2 = i;
	printf("%d %d\n", k1, k2);
	int t1 = -1, t2 = -1;
	for(int i = 1-n+N; i <= n-1+N; i++)
		if(t1 == -1 || sum2[i] > sum2[t1]) t1 = i;
	for(int i = 1-n+N; i <= n-1+N; i++)
		if(i != t1 && (t2 == -1 || sum2[i] > sum2[t2])) t2 = i;
	t1 -= N; t2 -= N;
	printf("%d %d\n", t1, t2);
	int x1 = (k1 + t1) / 2, y1 = (k1 - t1) / 2;
	int x2 = (k2 + t2) / 2, y2 = (k2 - t2) / 2;
	long long ans = sum1[k1] + sum1[k2] + sum2[t1+N] + sum2[t2+N];
	ans = ans - a[x1][y1] - a[x2][y2];
	printf("%lld\n", ans);
	printf("%d %d %d %d\n", x1, y1, x2, y2);
	return 0;
}
