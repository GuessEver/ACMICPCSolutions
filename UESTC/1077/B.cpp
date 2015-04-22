#include <cstdio>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char cap[100][100];
int sx, sy, sk;
bool found;

void dfs(int x, int y, int dir)
{
	if(found) return;
	if(cap[x][y] == 'x')
	{
		cap[x][y] = '&';
		found = 1;
		return;
	}
	int nx = x + dx[dir], ny = y + dy[dir], ndir = dir;
	if(cap[nx][ny] == '/' && dir == 0) ndir = 1;
	else if(cap[nx][ny] == '/' && dir == 1) ndir = 0;
	else if(cap[nx][ny] == '/' && dir == 2) ndir = 3;
	else if(cap[nx][ny] == '/' && dir == 3) ndir = 2;
	else if(cap[nx][ny] == '\\' && dir == 0) ndir = 3;
	else if(cap[nx][ny] == '\\' && dir == 1) ndir = 2;
	else if(cap[nx][ny] == '\\' && dir == 2) ndir = 1;
	else if(cap[nx][ny] == '\\' && dir == 3) ndir = 0;
	dfs(nx, ny, ndir);
}

int main()
{
	int cas = 0;
	while(scanf("%d%d", &m, &n) == 2 && n && m)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", cap[i] + 1);
			for(int j = 1; j <= m; j++)
				if(cap[i][j] == '*')
				{
					sx = i; sy = j;
					if(i == 1) sk = 2;
					else if(i == n) sk = 0;
					else if(j == 1) sk = 1;
					else if(j == m) sk = 3;
				}
		}
		found = 0;
		dfs(sx, sy, sk);
		printf("HOUSE %d\n", ++cas);
		for(int i = 1; i <= n; i++) puts(cap[i]+1);
	}
	return 0;
}
