#include <cstdio>

const int N = 1000 + 10;

int n, m, a[N][N];
int row[N][N];

int cnt(int x, int y, int t)
{
	return row[x+t-1][y+t-1] 
		- row[x-1][y+t-1] - row[x+t-1][y-1] 
		+ row[x-1][y-1];
}

bool check(int res)
{
	for(int i = 1; i <= n-res+1; i++)
		for(int j = 1; j <= m-res+1; j++) if(a[i][j] == 1)
			if(cnt(i, j, res) == res * res)
				return 1;
	return 0;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && n && m)
	{
		for(int i = 1; i <= n; i++)
		{
			row[i][0] = 0;
			for(int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				row[i][j] = row[i][j-1] + a[i][j];
			}
			for(int j = 1; j <= m; j++)
				row[i][j] += row[i-1][j];
		}
		int tmp = n; if(tmp > m) tmp = m;
		int low = 0, high = tmp, ans = 0;
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			if(check(mid)) { ans = mid; low = mid + 1; }
			else high = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
