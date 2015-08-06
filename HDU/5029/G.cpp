// Solution: www.guessbug.com/problem/HDU/5029
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 100000 + 10;

int n, m;
vector<int> path[N];

// Heavy-Light Decomposition
int size[N], father[N], deep[N], heavy_son[N];
int top[N], segid[N], treeid[N], time_stamp;
void dfs1(int x, int fa, int deepth)
{
	size[x] = 1; father[x] = fa; deep[x] = deepth;
	for(vector<int>::iterator it = path[x].begin(); it != path[x].end(); it++)
	{
		if(*it == father[x]) continue;
		dfs1(*it, x, deepth + 1);
		size[x] += size[*it];
		if(size[*it] > size[heavy_son[x]]) heavy_son[x] = *it;
	}
}
void dfs2(int x, int topx)
{
	top[x] = topx;
	segid[x] = ++time_stamp; treeid[time_stamp] = x;
	if(heavy_son[x]) dfs2(heavy_son[x], topx); // not leaf
	for(vector<int>::iterator it = path[x].begin(); it != path[x].end(); it++)
		if(*it != father[x] && *it != heavy_son[x])
			dfs2(*it, *it);
}
// Heavy-Light Decomposition ---- END


vector<int> add[N], del[N];
void change(int a, int b, int c)
{
	while(top[a] != top[b])
	{
		if(deep[top[a]] < deep[top[b]]) std::swap(a, b);
		add[segid[top[a]]].push_back(c);
		del[segid[a]].push_back(c);
		a = father[top[a]];
	}
	if(deep[a] > deep[b]) std::swap(a, b);
	add[segid[a]].push_back(c);
	del[segid[b]].push_back(c);
}

int tr[N*4], cnt[N], ans[N];
void modify(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		cnt[l] += c;
		tr[p] = cnt[l] ? l : 0;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) modify(p*2, l, mid, a, c);
	else modify(p*2+1, mid+1, r, a, c);
	if(cnt[tr[p*2]] > cnt[tr[p*2+1]]) tr[p] = tr[p*2];
	else if(cnt[tr[p*2]] < cnt[tr[p*2+1]]) tr[p] = tr[p*2+1];
	else if(cnt[tr[p*2]] == cnt[tr[p*2+1]]) tr[p] = std::min(tr[p*2], tr[p*2+1]);
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		time_stamp = 0;
		for(int i = 1; i <= n; i++)
		{
			size[i] = father[i] = heavy_son[i] = 0;
			deep[i] = top[i] = segid[i] = 0;
			path[i].clear();
			add[i].clear(); del[i].clear();
		}
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			path[x].push_back(y);
			path[y].push_back(x);
		}
		dfs1(1, 0, 1);
		dfs2(1, 1);
		while(m--)
		{
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			change(x, y, z);
		}
		memset(tr, 0, sizeof(tr));
		memset(cnt, 0, sizeof(cnt));
		/*for(int i = 1; i <= n; i++)
		{
			for(vector<int>::iterator it = add[i].begin(); it != add[i].end(); it++) printf("+%d ", *it);
			for(vector<int>::iterator it = del[i].begin(); it != del[i].end(); it++) printf("-%d ", *it);
			puts("");
		}*/
		for(int i = 1; i <= n; i++)
		{
			for(vector<int>::iterator it = add[i].begin(); it != add[i].end(); it++)
				modify(1, 1, 100000, *it, +1);
			ans[treeid[i]] = tr[1];
			for(vector<int>::iterator it = del[i].begin(); it != del[i].end(); it++)
				modify(1, 1, 100000, *it, -1);
		}
		for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
