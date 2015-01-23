#include <cstdio>
#include <cstring>

const int N = 500 + 10;

int n, m, a[N][N], f[N][N];
int pre[N][N];

bool check(int M)
{
	f[1][0] = a[1][1] + M;
	for(int i = 1; i <= n; i++)
		for(int j = 1;j <= m; j++)
		{
			f[i][j] = -2000; pre[i][j] = -1;
			f[1][1] = M;
			int tmp = f[i-1][j] + a[i][j];
			if(i > 1 && tmp > f[i][j])
			{
				f[i][j] = tmp;
				pre[i][j] = 1;
			}
			tmp = f[i][j-1] + a[i][j];
			if(j > 1 && tmp > f[i][j])
			{
				f[i][j] = tmp;
				pre[i][j] = 2;
			}
		}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= m; j++) printf("%d ", f[i][j]);
		printf("\n");
	} printf("\n");
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1;j <= m; j++) printf("%d ", pre[i][j]);
		printf("\n");
	} printf("\n===========\n");
	return pre[n][m] == 1 || pre[n][m] == 2;
}

int solve()
{
	int L = 1, R = 2000010, M;
	while(L < R)
	{
		M = (L + R) >> 1;
		if(check(M)) R = M;
		else L = M + 1;
	}
	return R;
}

int main()
{
	freopen("A.in", "r", stdin);
	//freopen("A2.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		//printf("%d\n", solve());
		check(0);
	}
	return 0;
}
