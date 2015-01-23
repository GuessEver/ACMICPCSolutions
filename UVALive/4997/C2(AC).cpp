#include <cstdio>
#include <cstring>

const int dx[] = {-1, 1,  0, 0};
const int dy[] = { 0, 0, -1, 1};
const int DX[] = {-2, 2, -2,  2, -2, 2, -1,  1, -1, 1, -1,  0,  1, -1, 0, 1};
const int DY[] = {0,  0, -1, -1,  1, 1, -1, -1,  1, 1, -2, -2, -2,  2, 2, 2}; // 16

int n;
char cap[20][20];
struct Point{int x, y;}po[300];
int L;
bool getAnswer;

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(cap[i][j] == '.') return 0;
	return 1;
}

bool can(int x, int y)
{
	if(cap[x][y] != '.') return 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k], ny = y + dy[k];
		if(nx < 1 || nx > n || ny < 1 || ny > n) return 0;
		if(cap[nx][ny] != '.') return 0;
	}
	return 1;
}

void write(int x, int y, char ch)
{
	for(int k = 0; k < 4; k++)
		cap[x+dx[k]][y+dy[k]] = ch;
	cap[x][y] = ch;
}


void solve()
{
	L = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(!can(i, j)) continue;
			char wr = 'Q';
			write(i, j, wr);
			po[++L] = (Point){i, j};
		}
}

bool ok(int x, int y, char ch)
{
	for(int k = 0; k < 16; k++)
	{
		int nx = x + DX[k], ny = y + DY[k];
		if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
		if(cap[nx][ny] == ch) return 0;
	}
	return 1;
}

void dfs(int x)
{
	if(getAnswer) return;
	if(x > L)
	{
		getAnswer = 1;
		return;
	}
	for(char ch = 'B'; ch <= 'D'; ch++)
	{
		if(!ok(po[x].x, po[x].y, ch)) continue;
		write(po[x].x, po[x].y, ch);
		dfs(x+1);
		if(getAnswer) return;
	}
	write(po[x].x, po[x].y, 'Q');
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(cap, 0, sizeof(cap));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%s", cap[i]+1);
		solve();
		if(!check()) printf("Case %d: Not Possible!\n", cas);
		else{
			getAnswer = 0;
			dfs(1);
			if(!getAnswer) printf("Case %d: Not Possible!\n", cas);
			else{
				printf("Case %d:\n", cas);
				for(int i = 1; i <= n; i++)
				{
					for(int j = 1; j <= n; j++) putchar(cap[i][j]);
					puts("");
				}
			}
		}
	}
	return 0;
}
