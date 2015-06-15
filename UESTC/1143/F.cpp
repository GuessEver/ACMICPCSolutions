#include <cstdio>
#include <algorithm>

const int N = 200 + 10;

int n, m, g[N][N];
int v[N], h[N];
int S, T;

int sap(int x, int flow)
{
	if(x == n) return flow;
	int res = 0;
	for(int i = S; i <= T; i++)
		if(g[x][i] && h[x] == h[i] + 1)
		{
			int t = sap(i, std::min(g[x][i], flow - res));
			res += t; g[x][i] -= t; g[i][x] += t;
			if(res == flow) return res;
			if(h[S] >= T) return res;
		}
	if(h[S] >= T) return res;
	if((--v[h[x]]) == 0) h[S] = T;
	++v[++h[x]];
	return res;
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] += z;
	}
	v[0] = T; S = 1; T = n;
	int maxflow = 0;
	while(h[S] < T) maxflow += sap(1, 0x3f3f3f3f);
	printf("%d\n", maxflow);
	return 0;
}
