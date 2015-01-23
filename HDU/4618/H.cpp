#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

const int N = 700 + 10;

int n, m, a[N][N];

bool check(int x, int y, int p)
{
	for(int i = x; i <= x + p - 1; i++)
		for(int l = y, r = y + p - 1; l <= r; l++, r--)
			if(a[i][l] != a[i][r]) return 0;
	for(int i = y; i <= y + p - 1; i++)
		for(int u = x, d = x + p - 1; u <= d; u++, d--)
			if(a[u][i] != a[d][i]) return 0;
	return 1;
}

int solve()
{
	for(int P = min(n, m); P >= 1; P--)
		for(int i = 1; i <= n - P + 1; i++)
			for(int j = 1; j <= m - P + 1; j++)
				if(check(i, j, P)) return P;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", solve());
	}
	return 0;
}
