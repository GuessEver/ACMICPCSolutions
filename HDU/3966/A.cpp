// Solution: www.guessbug.com/problem/HDU/3966
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;
// HDU 3966 : Increase or decrease a value on path [x - y] on a tree.
//            Query a value of a certain point
const int N = 50000 + 10;

int n, m, q, a[N];
vector<int> path[N];

// Heavy-Light Decomposition
int size[N], father[N], deep[N], heavy_son[N];
int top[N], segid[N], time_stamp;
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
	segid[x] = ++time_stamp;
	if(heavy_son[x]) dfs2(heavy_son[x], topx); // not leaf
	for(vector<int>::iterator it = path[x].begin(); it != path[x].end(); it++)
		if(*it != father[x] && *it != heavy_son[x])
			dfs2(*it, *it);
}
// Heavy-Light Decomposition ---- END

int add[N*4];
void pushDown(int p)
{
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
}
void modify(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		add[p] += c;
		return;
	}
	int mid = l + (r - l) / 2;
	pushDown(p);
	if(a <= mid) modify(p*2, l, mid, a, b, c);
	if(b > mid) modify(p*2+1, mid+1, r, a, b, c);
}
int query(int p, int l, int r, int a)
{
	if(l == r && l == a) return add[p];
	int mid = l + (r - l) / 2;
	pushDown(p);
	if(a <= mid) return query(p*2, l, mid, a);
	else return query(p*2+1, mid+1, r, a);
}

void change(int a, int b, int c)
{
	while(top[a] != top[b])
	{
		if(deep[top[a]] < deep[top[b]]) std::swap(a, b);
		modify(1, 1, n, segid[top[a]], segid[a], c);
		a = father[top[a]];
	}
	if(deep[a] > deep[b]) std::swap(a, b);
	modify(1, 1, n, segid[a], segid[b], c);
}

int main()
{
	while(scanf("%d%d%d", &n, &m, &q) == 3)
	{
		time_stamp = 0;
		for(int i = 1; i <= n; i++)
		{
			size[i] = father[i] = heavy_son[i] = 0;
			deep[i] = top[i] = segid[i] = 0;
			path[i].clear();
		}
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			path[x].push_back(y);
			path[y].push_back(x);
		}
		dfs1(1, 0, 1);
		dfs2(1, 1);
		memset(add, 0, sizeof(add));
		for(int i = 1; i <= n; i++) change(i, i, a[i]);
		while(q--)
		{
			char op; scanf(" %c", &op);
			if(op == 'I' || op == 'D')
			{
				int a, b, c; scanf("%d%d%d", &a, &b, &c);
				if(op == 'I') change(a, b, c);
				else change(a, b, -c);
			}
			else {
				int x; scanf("%d", &x);
				printf("%d\n", query(1, 1, n, segid[x]));
			}
		}
	}
	return 0;
}
