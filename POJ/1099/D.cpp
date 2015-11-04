#include <cstdio>
#include <cstring>
int n, m, k;
char s[1000][1000];

bool check(int x, int y)
{
	if(x < 0 || x >= n) return 0;
	if(y < 0 || y >= m) return 0;
	return s[x][y] == ' ';
}

bool Try(int x, int y, bool left, bool up)
{
	if(left && !check(x, y - 2)) return 0;
	if(!left && !check(x, y + 2)) return 0;
	if(up && !check(x - 2, y)) return 0;
	if(!up && !check(x + 2, y)) return 0;
	if(left)
	{
		s[x][y - 1] = '-';
		s[x][y - 2] = 'H';
	}
	else {
		s[x][y + 1] = '-';
		s[x][y + 2] = 'H';
	}
	if(up)
	{
		s[x - 1][y] = '|';
		s[x - 2][y] = 'H';
	}
	else {
		s[x + 1][y] = '|';
		s[x + 2][y] = 'H';
	}
	return 1;
}

int main()
{
	int cas = 0;
	while(scanf("%d", &k) == 1 && k)
	{
		++cas;
		printf("%sCase %d:\n\n", cas > 1 ? "\n" : "", cas);
		m = 4 * k + 3; n = 4 * k - 1;
		memset(s, ' ', sizeof(s));
		for(int j = 0; j < m; j++) s[0][j] = s[n - 1][j] = '*';
		for(int i = 0; i < n; i++) s[i][0] = s[i][m - 1] = '*';
		for(int i = 1; i < n; i += 4)
			for(int j = 3; j < m; j += 4)
			{
				s[i][j] = 'O';
				int x; scanf("%d", &x);
				if(x == 1)
				{
					s[i][j - 1] = s[i][j + 1] = '-';
					s[i][j - 2] = s[i][j + 2] = 'H';
				}
				else if(x == -1)
				{
					s[i - 1][j] = s[i + 1][j] = '|';
					s[i - 2][j] = s[i + 2][j] = 'H';
				}
				else { // x == 0
					Try(i, j, 1, 1) || Try(i, j, 0, 1) 
						|| Try(i, j, 1, 0) || Try(i, j, 0, 0);
				}
			}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++) putchar(s[i][j]);
			puts("");
		}
	}
	return 0;
}
