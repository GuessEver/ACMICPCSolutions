#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;
const int UPDeepth = 20;

int n;
struct Link{
	int y;
	Link *next;
}*head[N];
struct Edge{ int x, y; }edge[N];
bool notRoot[N];
int ancient[N][UPDeepth+1];
int deep[N];
int dfsSeq[N*2], dfsCnt = 0;
int in[N], out[N], value[N];
int val[N*2*4];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x, int deepth, int father)
{
	dfsSeq[++dfsCnt] = x;
	deep[x] = deepth;
	ancient[x][0] = father;
	for(Link *p = head[x]; p; p = p -> next)
		dfs(p -> y, deepth + 1, x);
	dfsSeq[++dfsCnt] = -x;
}

void getLCA()
{
	for(int j = 1; j <= UPDeepth; j++)
		for(int i = 1; i <= n; i++)
			ancient[i][j] = ancient[ancient[i][j-1]][j-1];
}

int LCA(int x, int y)
{
	if(deep[x] > deep[y]) std::swap(x, y); // deep[x] <= deep[y]
	for(int j = UPDeepth; j >= 0; j--)
		if(deep[x] <= deep[ancient[y][j]]) y = ancient[y][j];
	if(x == y) return x;
	for(int j = UPDeepth; j >= 0; j--)
		if(ancient[x][j] != ancient[y][j])
		{
			x = ancient[x][j];
			y = ancient[y][j];
		}
	return ancient[y][0];
}

void modify(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p] = c;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) modify(p*2, l, mid, a, c);
	else modify(p*2+1, mid+1, r, a, c);
	val[p] = val[p*2] + val[p*2+1];
}
int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int mid = l + (r - l) / 2, res = 0;
	if(a <= mid) res += query(p*2, l, mid, a, b);
	if(b > mid) res += query(p*2+1, mid+1, r, a, b);
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		scanf("%d", &value[y]);
		inLink(x, y); notRoot[y] = 1;
		edge[i] = (Edge){x, y};
	}
	for(int i = 1; i <= n; i++) if(!notRoot[i]) dfs(i, 1, 0);
	for(int i = 1; i <= dfsCnt; i++)
	{
		int x = dfsSeq[i];
		if(x > 0) in[x] = i; else out[-x] = i;
		//printf("%d ", dfsSeq[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		modify(1, 1, 2*n, in[i], value[i]);
		modify(1, 1, 2*n, out[i], -value[i]);
	}
	getLCA();
	int q; scanf("%d", &q);
	while(q--)
	{
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
		{
			int A = LCA(x, y);
			//printf("(%d, %d) - LCA = %d\n", x, y, A);
			int res = query(1, 1, 2*n, in[A], in[x]) + query(1, 1, 2*n, in[A], in[y]) - value[A] - value[A];
			printf("%d\n", res);
		}
		else {
			x = edge[x].y;
			value[x] = y;
			modify(1, 1, 2*n, in[x], y);
			modify(1, 1, 2*n, out[x], -y);
		}
	}
	return 0;
}
