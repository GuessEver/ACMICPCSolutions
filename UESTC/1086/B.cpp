#include <cstdio>
#include <cstring>

const int N = 1000 + 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int cap[N][N], n, m;
int expand[N][N][4];

bool check(int x, int y)
{
	if(x < 1 || x > n) return 0;
	if(y < 1 || y > m) return 0;
	return cap[x][y];
}

void Solve()
{
	memset(expand, 0, sizeof(expand));
	// up
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 1; j--)
			if(cap[i][j] && check(i-1, j))
			{
				if(check(i-1, j+1)) expand[i][j][0] = expand[i-1][j+1][0] + 2;
				else expand[i][j][0] = 1;
			}
	// right
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			if(cap[i][j] && check(i, j+1))
			{
				if(check(i+1, j+1)) expand[i][j][1] = expand[i+1][j+1][1] + 2;
				else expand[i][j][1] = 1;
			}
	// down
	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= m; j++)
			if(cap[i][j] && check(i+1, j))
			{
				if(check(i+1, j-1)) expand[i][j][2] = expand[i+1][j-1][2] + 2;
				else expand[i][j][2] = 1;
			}
	// left
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(cap[i][j] && check(i, j-1))
			{
				if(check(i-1, j-1)) expand[i][j][3] = expand[i-1][j-1][3] + 2;
				else expand[i][j][3] = 1;
			}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%1d", &cap[i][j]);
		Solve();
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) if(cap[i][j])
			{
				int res = 1;
				for(int k = 0; k < 4; k++) res += expand[i][j][k];
				if(res > ans) ans = res;
				//printf("(%d, %d) : %d\n", i, j, res);
			}
		printf("%d\n", ans);
	}
	return 0;
}
