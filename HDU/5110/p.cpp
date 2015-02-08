#include <cstdio>

int n, m, q;
char cap[1010][1010];
int sum[1010][1010];

int main()
{
	while(scanf("%d%d%d", &n, &m, &q) == 3)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", &cap[i][1]);
			sum[i][0] = 0;
			for(int j = 1; j <= m; j++)
				sum[i][j] = sum[i][j-1] + (cap[i][j] == 'X');
		}
		while(q--)
		{
			int x, y, d; scanf("%d%d%d", &x, &y, &d);
			int res = 0, left = y, right = y;
			if(d == 0)
			{
				printf("%d\n", cap[x][y] == 'X');
				continue;
			}
			while(x >= 1)
			{
				res += sum[x][right] - sum[x][left-1];
				x -= d;
				left -= d; if(left <= 0) left = 1;
				right += d; if(right > m) right = m;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
