#include <cstdio>
#include <algorithm>
const int N = 100 + 10;

int n, m, a[N][N], sum;

void solve1()
{
	int dir = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++) putchar(dir ? 'R' : 'L');
		if(i < n) putchar('D');
		dir = 1 - dir;
	}
}
void solve2()
{
	int dir = 1;
	for(int j = 1; j <= m; j++)
	{
		for(int i = 1; i < n; i++) putchar(dir ? 'D' : 'U');
		if(j < m) putchar('R');
		dir = 1 - dir;
	}
}
void getXY(int dir, int x, int y, int &x1, int &y1)
{
	x1 = x; y1 = y;
	if(dir == 1) x1++;
	else if(dir == 2 || dir == 4) y1++;
	else x1--;
}
void solve3(int x, int y)
{
	int xx = x % 2 == 0 ? x - 1 : x + 1;
	int dir = 1;
	for(int i = 1; i < x && i < xx; i++)
	{
		for(int j = 1; j < m; j++) putchar(dir ? 'R' : 'L');
		putchar('D'); dir = 1 - dir;
	}
	dir = 1; // 1,2,3,4 : DRUR
	int sx = std::min(x, xx), sy = 1;
	int tx = std::max(x, xx), ty = m;
	while(sx != tx || sy != ty)
	{
		int nx, ny; getXY(dir, sx, sy, nx, ny);
		if(nx == x && ny == y)
		{
			dir--;
			if(dir < 1) dir = 4;
			getXY(dir, sx, sy, nx, ny);
		}
		sx = nx; sy = ny;
		if(dir == 1) putchar('D');
		else if(dir == 2 || dir == 4) putchar('R');
		else putchar('U');
		dir = dir + 1; if(dir > 4) dir = 1;
	}
	if(tx != n)
	{
		putchar('D');
		dir = 0;
		for(int i = tx + 1; i <= n; i++)
		{
			for(int j = 1; j < m; j++) putchar(dir ? 'R' : 'L');
			if(i < n) putchar('D');
			dir = 1 - dir;
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2)
	{
		sum = 0;
		int x = -1, y = -1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				sum += a[i][j];
				if((i + j) % 2 == 1 && (x == -1 || a[i][j] < a[x][y]))
				{
					x = i;
					y = j;
				}
			}
		if(n % 2 || m % 2)
		{
			printf("%d\n", sum);
			if(n % 2) solve1(); else solve2();
		}
		else {
			//printf("x = %d, y = %d\n", x, y);
			printf("%d\n", sum -= a[x][y]);
			solve3(x, y);
		}
		puts("");
	}
	return 0;
}
