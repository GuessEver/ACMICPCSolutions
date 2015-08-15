#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, g[N][N];
int v[N], h[N];
int S, T;
char cap[50][50];

int sap(int x, int flow)
{
	if(x == T) return flow;
	int res = 0;
	for(int i = S; i <= T; i++)
		if(g[x][i] && h[x] == h[i] + 1)
		{
			int t = sap(i, std::min(g[x][i], flow - res));
			res += t; g[x][i] -= t; g[i][x] += t;
			if(res == flow) return res;
			//if(h[S] >= T) return res;
		}
	if(h[S] >= T) return res;
	if((--v[h[x]]) == 0) h[S] = T;
	++v[++h[x]];
	return res;
}

inline int I(int x, int y) { return (x - 1) * m + y + 1; }
inline int O(int x, int y) { return (x - 1) * m + y + 1 + n * m; }

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", cap[i] + 1);
	S = 1; T = O(n, m) + 1 + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(cap[i][j] == 'W') g[S][I(i, j)] = 1;
			else if(cap[i][j] == 'N') g[O(i, j)][T] = 1;
			else {
				for(int k = 0; k < 4; k++)
				{
					int x = i + dx[k], y = j + dy[k];
					if(x < 1 || x > n || y < 1 || y > m) continue;
					if(cap[x][y] == 'W') g[O(x, y)][I(i, j)] = 1;
					else if(cap[x][y] == 'N') g[O(i, j)][I(x, y)] = 1;
				}
			}
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			g[I(i, j)][O(i, j)] = 1;
	v[0] = T;
	int maxflow = 0;
	while(h[S] < T) maxflow += sap(S, 0x3f3f3f3f);
	printf("%d\n", maxflow);
	return 0;
}

