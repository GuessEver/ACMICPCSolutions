#include <cstdio>
#include <cstring>

int n, m;
char cap[100][100];

int main()
{
	memset(cap, '.', sizeof(cap));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		if(i % 2 == 1)
			for(int j = 1; j <= m; j++) cap[i][j] = '#';
		else if(i % 4 == 0)
			cap[i][1] = '#';
		else if(i % 2 == 0)
			cap[i][m] = '#';
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++) putchar(cap[i][j]);
		puts("");
	}
	return 0;
}
