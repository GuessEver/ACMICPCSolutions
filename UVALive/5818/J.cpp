#include <cstdio>
#include <cstring>

const int N = 100 + 10;
int n, m, v[N];
int cap[N][N];
int ans, pos;

void dfs(int x)
{
	ans += v[x]; pos = x;
	int k = -1;
	for(int i = 0; i < n; i++)
		if(cap[x][i] && (k == -1 || v[i] > v[k])) k = i;
	if(k == -1) return;
	dfs(k);
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(cap, 0, sizeof(cap));
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", &v[i]);
		while(m--)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[x][y] = 1;
		}
		ans = pos = 0;
		dfs(0);
		printf("Case %d: %d %d\n", cas, ans, pos);
	}
	return 0;
}
