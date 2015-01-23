#include <cstdio>

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int a[100][100], n, m;
int eat[100][100];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	bool can = 1;
	int x = 1, y = 1;
	int res = 0;
	while(can)
	{
		eat[x][y] = 1;
		res += a[x][y];
		can = 0;
		if(x == n && y == m) break;
		int newx, newy;
		int maxa = 0;
		for(int k = 0; k < 4; k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if(!eat[xx][yy] && a[xx][yy] > maxa)
			{
				maxa = a[xx][yy];
				newx = xx;
				newy = yy;
				can = 1;
			}
		}
		x = newx; y = newy;
	}
	printf("%d\n", res);
}
