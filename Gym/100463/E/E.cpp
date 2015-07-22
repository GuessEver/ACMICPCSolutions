#include <cstdio>
#include <cstring>

const int N = 100000 + 10;
const int mod = 1000000000 + 7;

int n, m;
int f[N], sz[N], num[N];
bool unique[N];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }
void merge(int x, int y)
{
	int rx = getroot(x), ry = getroot(y);
	unique[rx] |= unique[ry]; num[rx]++;
	if(x == y) { unique[rx] = 1; return; }
	if(rx != ry) 
	{
		sz[rx] += sz[ry];
		num[rx] += num[ry];
	}
	f[ry] = rx;
}

int solve()
{
	int res = 1;
	for(int i = 0; i < m; i++) if(f[i] == i)
	{
		//printf("%d: %d %d %d\n", i, sz[i], num[i], unique[i]);
		if(num[i] > sz[i]) return 0;
		if(num[i] == sz[i]) res = res * (unique[i] ? 1ll : 2ll) % mod;
		else res = 1ll * res * sz[i] % mod;
	}
	return res % mod;
}

int main()
{
	int cas = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 0; i < m; i++) f[i] = i;
		for(int i = 0; i < m; i++) sz[i] = 1;
		memset(num, 0, sizeof(num));
		memset(unique, 0, sizeof(unique));
		for(int i = 1; i <= n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			merge(x, y);
		}
		printf("Case %d: %d\n", ++cas, solve());
	}
	return 0;
}
