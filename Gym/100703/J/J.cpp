#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 2 * 100000 + 10;

int n, m, p;
int g[N];
struct Node{
	int t, i;
	bool operator < (const Node &b) const
	{
		return t < b.t;
	}
}a[N];
int f[N], sz[N];
vector<int> cap[N];
vector<int> out[N];
bool outside[N];
long long ans[N];

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }
void merge(int x, int y)
{
	int rx = getroot(x), ry = getroot(y);
	if(rx == ry) return;
	if(ry == 1) std::swap(rx, ry);
	sz[rx] += sz[ry];
	f[ry] = rx;
}

int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &a[i].t);
		a[i].i = i;
	}
	std::sort(a+2, a+1+n);
	for(int i = 1; i <= p; i++) scanf("%d", &g[i]);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++) sz[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int u, v;  scanf("%d%d", &u, &v);
		cap[u].push_back(v);
		cap[v].push_back(u);
	}
	for(int i = 1, j = 2; i <= p; i++)
	{
		for(; j <= n && a[j].t < g[i]; j++)
		{
			out[i].push_back(a[j].i);
			outside[a[j].i] = 1;
		}
	}
	/*for(int i = 1; i <= p; i++)
	{
		printf("out %d:\n", i);
		for(vector<int>::iterator jt = out[i].begin(); jt != out[i].end(); jt++)
			printf("%d ", *jt);
		puts("");
	}*/
	for(int i = 1; i <= n; i++) if(!outside[i])
	{
		outside[i] = 0;
		for(vector<int>::iterator it = cap[i].begin(); it != cap[i].end(); it++)
			if(!outside[*it]) merge(i, *it);
	}
	for(int i = p, j = n; i >= 1; i--)
	{
		//printf("%d : %d\n", i, sz[1]);
		ans[i] = 1ll * sz[1] * g[i];
		for(vector<int>::iterator jt = out[i].begin(); jt != out[i].end(); jt++)
		{
			outside[*jt] = 0;
			for(vector<int>::iterator it = cap[*jt].begin(); it != cap[*jt].end(); it++)
				if(!outside[*it]) merge(*jt, *it);
		}
	}
	for(int i = 1; i <= p; i++) printf("%I64d%s", ans[i], i == p ? "\n" : " ");
	return 0;
}
