#include <cstdio>
#include <algorithm>

const int N = 100 * 100 + 10;

int n, k, f[N];
struct EG{
	int x, y, z;
	bool operator < (const EG &b) const
	{
		return z < b.z;
	}
}edge[N];
int L = 0;

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) f[i] = i;
	int tmp, temp; scanf("%d", &tmp);
	for(int i = 2; i <= k; i++)
	{
		scanf("%d", &temp);
		f[getroot(temp)] = getroot(tmp);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			int a; scanf("%d", &a);
			if(j > i) edge[L++] = (EG){i, j, a};
		}
	std::sort(edge, edge+L);
	int res = 0;
	for(int i = 0; i < L; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		f[getroot(edge[i].x)] = getroot(edge[i].y);
		res += edge[i].z;
	}
	printf("%d\n", res);
	return 0;
}
