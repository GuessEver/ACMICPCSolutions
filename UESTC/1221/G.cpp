#include <cstdio>
#include <cstring>
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
char s[20][20];
int n = 9;
bool vis[20][20];

int dfs(int x, int y)
{
	if(vis[x][y]) return 0;
	vis[x][y] = 1;
	int res = 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if(nx < 0 || nx >= 9) continue;
		if(ny < 0 || ny >= 9) continue;
		if(s[nx][ny] == 'x') continue;
		if(s[nx][ny] == '.') res++;
		else res += dfs(nx, ny);
	}
	return res;
}

bool ok(int x, int y)
{
	if(s[x][y] != '.') return 0;
	s[x][y] = 'x';
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(s[i][j] == 'o' && !vis[i][j])
			{
				int cnt = dfs(i, j);
				// printf("@@ %d %d -> %d\n", i, j, cnt);
				if(cnt == 0) return 1;
			}
	s[x][y] = '.';
	return 0;
}

bool solve()
{
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(ok(i, j))
			{
				// printf("## %d %d\n", i, j);
				return 1;
			}
	return 0;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		for(int i = 0; i < 9; i++) scanf("%s", s[i]);
		if(solve()) printf("Case #%d: Can kill in one move!!!\n", cas);
		else printf("Case #%d: Can not kill in one move!!!\n", cas);
	}
	return 0;
}
