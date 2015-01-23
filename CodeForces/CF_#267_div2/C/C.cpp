#include <cstdio>
#include <algorithm>
using std::max;

const int N = 5000 + 10;

int n, m, k;
long long a[N], sum[N];
long long f[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%I64d", &a[i]);
		sum[i] = sum[i-1] + a[i];
	}
	for(int t = 1; t <= k; t++)
		for(int i = 1; i <= n; i++)
		{
			f[i][t] = f[i-1][t];
			if(i-m+1 > 0) f[i][t] = max(f[i][t], f[i-m][t-1] + (sum[i] - sum[i-m]));
		}
	/*for(int t = 1; t <= k; t++)
	{
		for(int i = 1; i <= n; i++)
			printf("%d ", f[i][t]);
		puts("");
	}*/
	printf("%I64d\n", f[n][k]);
	return 0;
}
