#include <cstdio>

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int DX[] = {-2, -2, -2, -1, -1, -1, -1,  0, 0,  1,  1, 1, 1,  2, 2, 2};
const int DY[] = {-1,  0,  1, -2, -1,  1,  2, -2, 2, -2, -1, 1, 2, -1, 0, 1};
/****************************************
	  OOO
	 OOBOO
	 OBBBO
	 OOBOO
	  OOO
  ****************************************/

int n;
char cap[20][20];
struct Point{int x, y; char col;}po[400];
int L;
bool getAnswer;

bool isCenter(int x, int y)
{
	if(cap[x][y] != '.') return 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx < 1 || nx > n || ny < 1 || ny > n) return 0;
		if(cap[nx][ny] != '.') return 0;
	}
	return 1;
}
void write(int x, int y, char ch)
{
	cap[x][y] = ch;
	for(int k = 0; k < 4; k++)
		cap[x+dx[k]][y+dy[k]] = ch;
}

bool full()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(cap[i][j] == '.') return 0;
	return 1;
}

bool check(int x, int y, char ch)
{
	for(int k = 0; k < 16; k++)
	{
		int nx = x + DX[k];
		int ny = y + DY[k];
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
		if(!check(po[x].x, po[x].y, ch)) continue;
		po[x].col = ch;
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
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%s", cap[i]+1);
		L = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(isCenter(i, j))
				{
					po[++L] = (Point){i, j};
					write(i, j, 'Q');
				}
		if(!full()) printf("Case %d: Not Possible!\n", cas);
		else{
			getAnswer = 0;
			dfs(1);
			if(!getAnswer) printf("Case %d: Not Possible!\n", cas);
			else{
				for(int i = 1; i <= L; i++) 
					write(po[i].x, po[i].y, po[i].col);
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
