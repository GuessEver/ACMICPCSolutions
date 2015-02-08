#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int n, m, q;
char cap[1010][1010];
int sum[1010][1010];
int f[1010][1010][50];

int main()
{
	while(scanf("%d%d%d", &n, &m, &q) == 3)
	{
		//memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", &cap[i][1]);
			sum[i][0] = 0;
			for(int j = 1; j <= m; j++)
				sum[i][j] = sum[i][j-1] + (cap[i][j] == 'X');
		}
		int Std = ceil(sqrt(1.0 * n));
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				for(int k = 1; k <= Std; k++)
				{
					f[i][j][k] = (cap[i][j] == 'X');
					if(i-k < 0) continue; // Make sure that : i-k >= 0
					if(j-k >= 0 && j+k <= m)
					{
						f[i][j][k] += f[i-k][j-k][k] + f[i-k][j+k][k] + (sum[i-k][j+k-1]-sum[i-k][j-k]);
						if(i-2*k >= 0) f[i][j][k] -= f[i-2*k][j][k];
					}
					else if(j-k >= 0) // j+k > m
					{
						f[i][j][k] += f[i-k][j-k][k] + (sum[i-k][m] - sum[i-k][j-k]);
						if(i-2*k >= 0) f[i][j][k] += (sum[i-2*k][m]-sum[i-2*k][j]);
					}
					else if(j+k <= m) // j-k < 0
					{
						f[i][j][k] += f[i-k][j+k][k] + (sum[i-k][j+k-1]-sum[i-k][0]);
						if(i-2*k >= 0 && j) f[i][j][k] += (sum[i-2*k][j-1]-sum[i-2*k][0]);
					}
					else{ // j+k > m && j-k < 0
						f[i][j][k] += f[i-k][1][k] + (sum[i-k][m]-sum[i-k][1]);
						if(i-2*k >= 0 && 1+k <= m) f[i][j][k] += (sum[i-2*k][m]-sum[i-2*k][1+k]);
					}
				}
		while(q--)
		{
			int x, y, d; scanf("%d%d%d", &x, &y, &d);
			if(d > Std)
			{
				int res = 0, left = y, right = y;
				while(x >= 1)
				{
					res += sum[x][right] - sum[x][left-1];
					x -= d;
					left -= d; if(left <= 0) left = 1;
					right += d; if(right > m) right = m;
				}
				printf("%d\n", res);
			}
			else printf("%d\n", f[x][y][d]);
		}
	}
	return 0;
}
