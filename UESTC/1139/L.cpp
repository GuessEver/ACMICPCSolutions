#include <cstdio>
#include <algorithm>

int m, n;
long long f[100];
int a[100], g[100][2];

int main()
{
	f[1] = 1; f[2] = 2;
	for(m = 3; f[m-1] < 1000000000000000000ll; m++)
	{
		f[m] = f[m-1] + f[m-2];
		//printf("f[%d] = %lld\n", m, f[m]);
	} m--;
	//printf("%d %lld\n", m, f[m]);
	int T; scanf("%d", &T);
	while(T--)
	{
		long long x; scanf("%lld", &x);
		n = 0; a[0] = 0;
		for(int i = m; i >= 1; i--)
			if(x >= f[i])
			{
				x -= f[i];
				a[++n] = i;
			}
		//for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
		for(int i = 1, j = n; i < j; i++, j--) std::swap(a[i], a[j]);
		for(int i = n; i >= 1; i--) a[i] = a[i] - a[i-1] - 1;
		//for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
		g[1][0] = 1; g[1][1] = a[1] / 2;
		for(int i = 2; i <= n; i++)
		{
			g[i][0] = g[i-1][0] + g[i-1][1];
			g[i][1] = g[i-1][0] * (a[i] / 2) + g[i-1][1] * ((a[i] + 1) / 2);
		}
		printf("%d\n", g[n][0] + g[n][1]);
	}
	return 0;
}
