#include <cstdio>

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
char a[110][110];

int count(int x, int y)
{
	int cnt = 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
		if(a[nx][ny] == 'o') cnt++;
	}
	return cnt;
}

bool check()
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			int cnt = count(i, j);
			if(cnt % 2 != 0) return 0;
		}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf(" %c", &a[i][j]);
	if(check()) puts("YES");
	else puts("NO");
	return 0;
}
