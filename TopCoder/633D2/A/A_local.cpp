#include <cstdio>
#include <string>
#include <vector>
using std::string;
using std::vector;

int n; 
vector<string> s;
string tmp;

void dfs(int x1, int y1, int x2, int y2)
{
	for(int i = y1; i <= y2; i++)
	{
		s[x1][i] = s[x2][i] = '#';
		//printf("%d %d\n", x1, i);
		//printf("%d %d\n", x2, i);
	}
	for(int i = x1; i <= x2; i++)
	{
		s[i][y1] = s[i][y2] = '#';
		//printf("%d %d\n", i, y1);
		//printf("%d %d\n", i, y2);
	}
	if(x1 == x2 && y1 == y2) return;
	/*	for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				putchar(s[i][j]);
			puts("");
		}puts("");*/
	dfs(x1+2, y1+2, x2-2, y2-2);
}

int main()
{
	scanf("%d", &n);
	for(int j = 0; j < n; j++) tmp += ' ';
	for(int i = 0; i < n; i++) s.push_back(tmp);
	dfs(0, 0, n-1, n-1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			putchar(s[i][j]);
		puts("");
	}
	return 0;
}
