#include <cstdio>
#include <cstring>

int n;
char s[100][100], t[100][100];
char ans[200][200];

bool check(int dx, int dy)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) if(s[i][j] == 'o')
		{
			int x = i + dx, y = j + dy;
			if(x < 0 || x >= n || y < 0 || y >= n) continue;
			if(s[x][y] == '.') return 0;
		}
	return 1;
}

void solve(int ox, int oy)
{
	for(int i = 0; i < 2 * n - 1; i++)
		for(int j = 0; j < 2 * n - 1; j++)
			if(ans[i][j] == 'x')
			{
				int dx = i - (n - 1), dy = j - (n - 1);
				int x = ox + dx, y = oy + dy;
				if(x < 0 || x >= n || y < 0 || y >= n) continue;
				if(t[x][y] == 'o') continue;
				t[x][y] = 'x';
			}
}

bool wrong()
{
	memset(t, '.', sizeof(t));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(s[i][j] == 'o') t[i][j] = 'o';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(t[i][j] == 'o') solve(i, j);
	/*for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) putchar(t[i][j]);
		puts("");
	}*/
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(s[i][j] != t[i][j]) return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	memset(ans, 'x', sizeof(ans)); ans[n-1][n-1] = 'o';
	for(int i = 0; i < 2 * n - 1; i++)
		for(int j = 0; j < 2 * n - 1; j++)
		{
			if(i == n - 1 && j == n - 1) continue;
			if(!check(i - (n - 1), j - (n - 1))) ans[i][j] = '.';
		}
	if(wrong()) puts("NO");
	else {
		puts("YES");
		for(int i = 0; i < 2 * n - 1; i++)
		{
			for(int j = 0; j < 2 * n - 1; j++) putchar(ans[i][j]);
			puts("");
		}
	}
	return 0;
}
