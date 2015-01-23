#include <cstdio>
#include <algorithm>
const int N = 500 + 10;
int f[N], n, m;
struct EG{
	int x, y, z;
}edge[N*N];

int getroot(int x) 
{
   	return f[x] == x ? x : f[x] = getroot(f[x]);
}

bool cmp(EG a, EG b) { return a.z < b.z; }

int kruskal()
{
	for(int i = 0; i <= n; i++) f[i] = i;
	std::sort(edge+1, edge+1+m, cmp);
	int res = 0;
	for(int i  = 1; i <= m; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		f[getroot(edge[i].x)] = getroot(edge[i].y);
		res += edge[i].z;
	}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
			int x, y, z; 
			scanf("%d%d%d", &x, &y, &z);
			edge[i] = (EG){x, y, z};
		}
		printf("%d\n", kruskal());
	}
	return 0;
}
