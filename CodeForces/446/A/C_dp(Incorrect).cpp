#include <cstdio>
#include <algorithm>
using std::max;

int n, a[100010], f[100010][2];

int main()
{
	freopen("C.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	a[n+1] = 2000000000;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > a[i-1])
		{
			f[i][0] = max(f[i][0], f[i-1][0] + 1);
			f[i][1] = max(f[i][1], f[i-1][1] + 1);
		}
		else f[i][0] = f[i][1] = 1;
		
		if(a[i+1] > a[i-1]+1)
		{
			f[i][1] = max(f[i][1], f[i-1][0] + 1);
			f[i+1][1] = max(f[i+1][1], f[i][1] + 1);
		}
		f[i][1] = max(f[i][1], f[i-1][0] + 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		printf("%d %d\n", f[i][0], f[i][1]);
		ans = max(max(ans, f[i][0]), f[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}
