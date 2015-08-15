#include <cstdio>
#include <algorithm>
const int N = 750 + 10;

struct Edge{
	int x, y, z;
	bool operator < (const Edge &b) const
	{
		return z < b.z;
	}
}edge[N*N];

int dis(int x1, int y1, int x2, int y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int x[N], y[N];
int n, m, Cnt;
int f[N];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			edge[Cnt++] = (Edge){i, j, dis(x[i], y[i], x[j], y[j])};
	scanf("%d", &m);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		f[getroot(u)] = getroot(v);
	}
	std::sort(edge, edge+Cnt);
	for(int i = 0; i < Cnt; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		printf("%d %d\n", edge[i].x, edge[i].y);
		f[getroot(edge[i].x)] = getroot(edge[i].y);
	}
	return 0;
}
