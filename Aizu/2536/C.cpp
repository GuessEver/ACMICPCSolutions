#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;
const int M = 10000 + 10;

int n, m;
struct EDGE{
	int x, y, z;
	bool operator < (const EDGE &b) const
	{
		return z < b.z;
	}
}edge[M];
int f[N];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= m; i++)
		{
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			edge[i] = (EDGE){x, y, z};
		}
		std::sort(edge+1, edge+1+m);
		int cnt = 0;
		for(int i = 1; i <= m; i++)
		{
			if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
			f[getroot(edge[i].x)] = getroot(edge[i].y);
			if(++cnt == n / 2)
			{
				printf("%d\n", edge[i].z);
				break;
			}
		}
	}
	return 0;
}
