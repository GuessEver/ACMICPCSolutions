#include <cstdio>

const int N = 100 + 10;

int n, m;
char cap[N][N], map[N][N];

void read()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", cap[i]);
}

void solve()
{
	for(int i = 0; i < n; i++)
	{
		int k = 0;
		if(i != 0 && map[i-1][0] == 'B') k = 1;
		for(int j = 0; j < m; j++)
		{
			map[i][j] = k == 0 ? 'B' : 'W';
			k++;
			k %= 2;
		}
	}
	//for(int i = 0; i < n; i++) puts(map[i]);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(cap[i][j] == '.') printf("%c", map[i][j]);
			else printf("%c", cap[i][j]);
		}
		puts("");
	}
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	read();
	solve();
	return 0;
}
