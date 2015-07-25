#include <cstdio>
#include <map>
#include <algorithm>
using std::map;
const int N = 100000 + 10;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

int n, m, a[N];
struct Query{
	int l, r, i;
	long long ans;
}q[N];
map<int, int> pos;
int pre[N];
long long val[N*4], add_val[N*4], his[N*4], add_his[N*4];

bool cmp_i(const Query &a, const Query &b)
{
	return a.i < b.i;
}
bool cmp_r(const Query &a, const Query &b)
{
	if(a.r == b.r) return a.l < b.l;
	return a.r < b.r;
}

void pushUp(int p)
{
	val[p] = std::max(val[p*2], val[p*2+1]);
	his[p] = std::max(his[p*2], his[p*2+1]);
}
void pushDown(int p)
{
	add_his[p*2] = std::max(add_his[p*2], add_val[p*2] + add_his[p]);
	add_his[p*2+1] = std::max(add_his[p*2+1], add_val[p*2+1] + add_his[p]);
	his[p*2] = std::max(his[p*2], val[p*2] + add_his[p]);
	his[p*2+1] = std::max(his[p*2+1], val[p*2+1] + add_his[p]);
	add_his[p] = 0;
	//////// Make sure the code above is correct
	add_val[p*2] += add_val[p]; add_val[p*2+1] += add_val[p];
	val[p*2] += add_val[p]; val[p*2+1] += add_val[p];
	add_val[p] = 0;
}

void modify(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		val[p] += c; add_val[p] += c;
		his[p] = std::max(his[p], val[p]);
		add_his[p] = std::max(add_his[p], add_val[p]);
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
	int mid = l + (r - l) / 2; long long res = -infll;
	pushDown(p);
	if(a <= mid) res = std::max(res, query(p*2, l, mid, a, b));
	if(b > mid) res = std::max(res, query(p*2+1, mid+1, r, a, b));
	pushUp(p);
	return res;
}

void Solve()
{
	std::sort(q+1, q+1+m, cmp_r);
	for(int i = 1, j = 1; i <= n; i++)
	{
		if(pre[i] + 1 <= i - 1) modify(1, 1, n, pre[i]+1, i-1, a[i]);
		for(; j <= m && q[j].r <= i; j++)
			q[j].ans = query(1, 1, n, q[j].l, q[j].r);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		modify(1, 1, n, i, i, a[i]);
		pre[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].i = i;
	}
	Solve();
	std::sort(q+1, q+1+m, cmp_i);
	for(int i = 1; i <= m; i++) printf("%lld\n", q[i].ans);
	return 0;
}
