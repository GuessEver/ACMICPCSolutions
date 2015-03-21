#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 500 + 10;
int n, m;
int a[N][N], b[N][N];
int A[N][N], B[N][N];
int f[N][N];

int solve(int x, int y)
{
	if(x == 0 || y == 0) return 0;
	if(f[x][y] != -1) return f[x][y];
	f[x][y] = std::max(solve(x-1, y) + A[x][y],
			solve(x, y-1) + B[x][y]);
	return f[x][y];
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) scanf("%d", &b[i][j]);
		for(int i = 1; i <= n; i++)
		{
			A[i][0] = 0;
			for(int j = 1; j <= m; j++) A[i][j] = A[i][j-1] + a[i][j];
		}
		for(int j = 1; j <= m; j++)
		{
			B[0][j] = 0;
			for(int i = 1; i <= n; i++) B[i][j] = B[i-1][j] + b[i][j];
		}
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(n, m));
	}
	return 0;
}
