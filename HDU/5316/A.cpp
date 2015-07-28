#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;
const long long inf = 0x3f3f3f3f3f3f3f3fll;

int n, m;
struct Node{
	long long oo, oe, eo, ee;
	void init()
	{
		oo = oe = eo = ee = -inf;
	}
}val[N*4];

void build(int p, int l, int r)
{
	val[p].init();
	if(l == r) return;
	int mid = l + (r - l) / 2;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
}

void update(Node &p, const Node &lc, const Node &rc)
{
	p.init();
	if(lc.oo != -inf && rc.eo != -inf) p.oo = std::max(p.oo, lc.oo + rc.eo);
	if(lc.oo != -inf) p.oo = std::max(p.oo, lc.oo);
	if(lc.oe != -inf && rc.oo != -inf) p.oo = std::max(p.oo, lc.oe + rc.oo);
	if(rc.oo != -inf) p.oo = std::max(p.oo, rc.oo);

	if(lc.oo != -inf && rc.ee != -inf) p.oe = std::max(p.oe, lc.oo + rc.ee);
	if(lc.oe != -inf && rc.oe != -inf) p.oe = std::max(p.oe, lc.oe + rc.oe);
	if(lc.oe != -inf) p.oe = std::max(p.oe, lc.oe);
	if(rc.oe != -inf) p.oe = std::max(p.oe, rc.oe);

	if(lc.ee != -inf && rc.oo != -inf) p.eo = std::max(p.eo, lc.ee + rc.oo);
	if(lc.eo != -inf && rc.eo != -inf) p.eo = std::max(p.eo, lc.eo + rc.eo);
	if(lc.eo != -inf) p.eo = std::max(p.eo, lc.eo);
	if(rc.eo != -inf) p.eo = std::max(p.eo, rc.eo);

	if(lc.eo != -inf && rc.ee != -inf) p.ee = std::max(p.ee, lc.eo + rc.ee);
	if(rc.ee != -inf) p.ee = std::max(p.ee, rc.ee);
	if(lc.ee != -inf && rc.oe != -inf) p.ee = std::max(p.ee, lc.ee + rc.oe);
	if(lc.ee != -inf) p.ee = std::max(p.ee, lc.ee);
}
void modify(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p].init();
		if(l & 1) val[p].oo = c;
		else val[p].ee = c;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) modify(p*2, l, mid, a, c);
	else modify(p*2+1, mid+1, r, a, c);
	update(val[p], val[p*2], val[p*2+1]);
}
Node query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int mid = l + (r - l) / 2;
	if(b <= mid) return query(p*2, l, mid, a, b);
	else if(a > mid) return query(p*2+1, mid + 1, r, a, b);
	else {
		Node lc = query(p*2, l, mid, a, mid);
		Node rc = query(p*2+1, mid+1, r, mid+1, b);
		Node res; res.init();
		update(res, lc, rc);
		return res;
	}
}

void printTree()
{
	printf("p\too\toe\teo\tee\n");
	for(int p = 1; p <= 15; p++)
	{
		long long oo = val[p].oo == -inf ? -1 : val[p].oo;
		long long oe = val[p].oe == -inf ? -1 : val[p].oe;
		long long eo = val[p].eo == -inf ? -1 : val[p].eo;
		long long ee = val[p].ee == -inf ? -1 : val[p].ee;
		printf("%d\t%lld\t%lld\t%lld\t%lld\n", p, oo, oe, eo, ee);
	}
	puts("=======");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			modify(1, 1, n, i, x);
		}
		//printTree();
		for(int i = 1; i <= m; i++)
		{
			int op, x, y; scanf("%d%d%d", &op, &x, &y);
			if(op == 0)
			{
				Node res = query(1, 1, n, x, y);
				printf("%lld\n", std::max(std::max(res.oo, res.oe), std::max(res.eo, res.ee)));
			}
			else {
				modify(1, 1, n, x, y);
			}
			//printTree();
		}
	}
	return 0;
}
