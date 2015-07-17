#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;
const int M = 30 + 10;

int n, m;
char s[N][M];
struct EG{
	int x, y, z;
	bool operator < (const EG &b) const
	{
		return z < b.z;
	}
}edge[N*N];
int Cnt;
int f[N];

int calc(int a, int b)
{
	int res = 0;
	for(int i = 0; i < m; i++)
		res = std::max(res, abs(s[a][i] - s[b][i]));
	return res;
}

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			edge[Cnt++] = (EG){i+1, j+1, calc(i, j)};
			//printf("%d %d : %d\n", i+1, j+1, calc(i, j));
		}
	std::sort(edge, edge+Cnt);
	for(int i = 1; i <= n; i++) f[i] = i;
	int res = 0;
	for(int i = 0; i < Cnt; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		f[getroot(edge[i].x)] = getroot(edge[i].y);
		res = edge[i].z;
	}
	printf("%d\n", res);
	return 0;
}
