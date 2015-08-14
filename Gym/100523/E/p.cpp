#include <cstdio>

const int N = 500000 + 10;

int n, m, d, l;
int a[N], cnt[N], ans = 0;

void solve(int x, int sign)
{
	ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= x - l && a[i] <= x + l)
			cnt[i] += sign;
		if(cnt[i] >= 1) ans++;
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &d, &l);
	for(int i = 2; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		solve(x, 1);
	}
	printf("%d\n", ans);
	for(int i = 1; i <= d; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		solve(x, -1); solve(y, 1);
		printf("%d\n", ans);
	}
	return 0;
}
