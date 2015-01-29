#include <cstdio>
#include <algorithm>
using std::min;

const int N = 40 + 10;
const int inf = 0x3f3f3f3f;

int n, p[N], t[N];
int f[N][4];

void solve()
{
	for(int i = 1; i <= n; i++) // f[i][k] k = 0, 1, 2, 3
	{
		// k = 1
		f[i][1] = inf;
		if(t[i] - t[i-1] >= 2 * p[i-1] + p[i])
			f[i][1] = min(f[i][1], f[i-1][1] + p[i-1] + p[i]);
		if(t[i] - t[i-1] >= 3 * p[i-1] + p[i])
			f[i][1] = min(f[i][1], f[i-1][2] + p[i-1] + p[i]);
		if(t[i] - t[i-1] >= 4 * p[i-1] + p[i])
			f[i][1] = min(f[i][1], f[i-1][3] + p[i-1] + p[i]);
		// k = 2
		f[i][2] = inf;
		if(t[i] - t[i-1] >= 2 * abs(p[i] - p[i-1]))
			f[i][2] = min(f[i][2], f[i-1][1] + abs(p[i] - p[i-1]));
		// k = 3
		f[i][3] = inf;
		if(t[i] - t[i-1] >= 3 * abs(p[i] - p[i-1]))
			f[i][3] = min(f[i][3], f[i-1][2] + abs(p[i] - p[i-1]));
		if(f[i][1] == inf && f[i][2] == inf && f[i][3] == inf)
		{
			printf("NG %d\n", i);
			return;
		}
	}
	int res = min(f[n][1], min(f[n][2], f[n][3]));
	printf("OK %d\n", res + p[n]);
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) scanf("%d%d", &p[i], &t[i]);
		solve();
	}
	return 0;
}
