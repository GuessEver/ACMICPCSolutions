#include <cstdio>

int n, m;
char s[200];

void solve()
{
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for(int j = 0; j < m; j++)
		{
			if(s[j] == 'O') cnt++;
		}
	}
	if(cnt & 1) printf("Maze\n");
	else printf("Fat brother\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		printf("Case %d: ", i);
		solve();
	}
	return 0;
}
