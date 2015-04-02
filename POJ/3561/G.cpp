#include <cstdio>

const int N = 10 + 10;

int n, m;
char cap[N][N], s[N][N];

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] != '.') return 0;
	return 1;
}

bool horizontal()
{
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = cap[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] != '.' && s[i][j] != '-') return 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '-')
			{
				for(int k = j; k <= m; k++)
				{
					if(s[i][k] == '-') s[i][k] = '.';
					else break;
				}
				return check();
			}
	return 0;
}
bool vertical()
{
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = cap[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] != '.' && s[i][j] != '|') return 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '|')
			{
				for(int k = i; k <= n; k++)
				{
					if(s[k][j] == '|') s[k][j] = '.';
					else break;
				}
				return check();
			}
	return 0;
}
bool diagonal_left()
{
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = cap[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] != '.' && s[i][j] != '/') return 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '/')
			{
				for(int x = i, y = j; x <= n && y >= 1; x++, y--)
				{
					if(s[x][y] == '/') s[x][y] = '.';
					else break;
				}
				return check();
			}
	return 0;
}
bool diagonal_right()
{
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = cap[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] != '.' && s[i][j] != '\\') return 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(s[i][j] == '\\')
			{
				for(int x = i, y = j; x <= n && y <= m; x++, y++)
				{
					if(s[x][y] == '\\') s[x][y] = '.';
					else break;
				}
				return check();
			}
	return 0;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf(" %c", &cap[i][j]);
		if(horizontal() || vertical() 
				|| diagonal_left() || diagonal_right()) puts("CORRECT");
		else puts("INCORRECT");
	}
	return 0;
}
