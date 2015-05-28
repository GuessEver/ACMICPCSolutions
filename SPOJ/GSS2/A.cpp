#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;
const int inf = 0x3f3f3f3f;

int n, m, a[N], pre[N], last[N*2];
struct Query{
	int idx, l, r;
	long long ans;
	void Read(int i)
	{
		scanf("%d%d", &l, &r);
		idx = i;
	}
}q[N];
long long his[N*4], val[N*4], add[N*4], add2[N*4];

bool cmp_i(Query a, Query b) { return a.idx < b.idx; }
bool cmp_r(Query a, Query b) { return a.r < b.r; }

void pushDown(int p)
{
	add2[p*2] = std::max(add2[p*2], add2[p] + add[p*2]);
	add2[p*2+1] = std::max(add2[p*2+1], add2[p] + add[p*2+1]);
	his[p*2] = std::max(his[p*2], add2[p] + val[p*2]);
	his[p*2+1] = std::max(his[p*2+1], add2[p] + val[p*2+1]);
	add2[p] = 0;
	add[p*2] += add[p];	add[p*2+1] += add[p];
	val[p*2] += add[p]; val[p*2+1] += add[p];
	add[p] = 0;
}

void pushUp(int p)
{
	val[p] = std::max(val[p*2], val[p*2+1]);
	his[p] = std::max(his[p*2], his[p*2+1]);
}

void modify(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		add[p] += c; val[p] += c;
		add2[p] = std::max(add2[p], add[p]);
		his[p] = std::max(his[p], val[p]);
		return;
	}
	int mid = l + (r - l) / 2;
	pushDown(p);
	if(a <= mid) modify(p*2, l, mid, a, b, c);
	if(b > mid) modify(p*2+1, mid+1, r, a, b, c);
	pushUp(p);
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return his[p];
	int mid = l + (r - l) / 2, res1 = 0, res2 = 0;
	pushDown(p);
	if(a <= mid) res1 = query(p*2, l, mid, a, b);
	if(b > mid) res2 = query(p*2+1, mid+1, r, a, b);
	pushUp(p);
	return std::max(res1, res2);
}

void Solve()
{
	std::sort(q+1, q+1+m, cmp_r); int i = 1;
	for(int t = 1; t <= q[m].r; t++)
	{
		if(pre[t]+1 <= t-1) modify(1, 1, n, pre[t]+1, t-1, a[t]);
		//for(int p = 1; p <= 18; p++) printf("%3lld ", his[p]); puts("");
		//for(int p = 1; p <= 18; p++) printf("%3lld ", add2[p]); puts("");
		//for(int p = 1; p <= 18; p++) printf("%3lld ", val[p]); puts("");
		//for(int p = 1; p <= 18; p++) printf("%3lld ", add[p]); puts(""); puts("");
		for( ; q[i].r == t; i++)
		{
			q[i].ans = query(1, 1, n, q[i].l, q[i].r);
			//printf("[%d, %d] -- modify:[%d, %d]\n", q[i].l, q[i].r, pre[q[i].r]+1, q[i].r-1);
			//for(int p = 1; p <= 18; p++) printf("%3lld ", his[p]); puts("");
			//for(int p = 1; p <= 18; p++) printf("%3lld ", add2[p]); puts("");
			//for(int p = 1; p <= 18; p++) printf("%3lld ", val[p]); puts("");
			//for(int p = 1; p <= 18; p++) printf("%3lld ", add[p]); puts(""); puts("");
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		modify(1, 1, n, i, i, a[i]);
		pre[i] = last[a[i]+N];
		last[a[i]+N] = i;
	}
	//for(int i = 1; i <= n; i++) printf("%d ", pre[i]); puts("");
	//for(int p = 1; p <= 10; p++) printf("%3lld ", his[p]); puts("");
	//for(int p = 1; p <= 10; p++) printf("%3lld ", val[p]); puts("");
	//for(int p = 1; p <= 10; p++) printf("%3lld ", add[p]); puts(""); puts("");
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) q[i].Read(i);
	Solve();
	std::sort(q+1, q+1+m, cmp_i);
	for(int i = 1; i <= m; i++) printf("%lld\n", q[i].ans);
	return 0;
}
