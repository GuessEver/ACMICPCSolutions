#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200 + 10;

int n1, n2, n;
bool cap[N][N];
int a[N], f[N][N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n1, &n2);
		memset(cap, 0, sizeof(cap));
		for(int i = 1; i <= n2; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[x][y] = cap[y][x] = 1;
		}
		for(int i = 1; i <= n1; i++) cap[i][i] = 1;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		memset(f, 0x3f, sizeof(f));
		// f[i][j] : the value of b[i] -> j
		for(int j = 1; j <= n1; j++) f[1][j] = (a[1] != j);
		for(int i = 2; i <= n; i++)
			for(int j = 1; j <= n1; j++)
				for(int k = 1; k <= n1; k++) if(cap[k][j])
					f[i][j] = std::min(f[i][j], f[i-1][k] + (a[i] != j));
		int res = 0x3f3f3f3f;
		for(int j = 1; j <= n1; j++) res = std::min(res, f[n][j]);
		printf("%d\n", res);
	}
	return 0;
}
