#include <cstdio>

struct SegmentTree{
	int add;
	SegmentTree *lc, *rc;
	void init()
	{
		lc = 0; rc = 0;
		add = 0;
	}
}*root;
int n, m, d = 0;

void pushDown(SegmentTree *&p)
{
	if(p -> add == 0) return;
	if(!p -> lc)
	{
		p -> lc = new SegmentTree;
		p -> lc -> init();
	}
	if(!p -> rc)
	{
		p -> rc = new SegmentTree;
		p -> rc -> init();
	}
	p -> lc -> add += p -> add;
	p -> rc -> add += p -> add;
	p -> add = 0;
}

void modify(SegmentTree *&p, int l, int r, int a, int b)
{
	if(!p)
	{
		p = new SegmentTree;
		p -> init();
	}
	if(a <= l && b >= r)
	{
		p -> add++;
		return;
	}
	pushDown(p);
	int mid = l + (r - l) / 2;
	if(a <= mid) modify(p -> lc, l, mid, a, b);
	if(b > mid) modify(p -> rc, mid+1, r, a, b);
}
int query(SegmentTree *p, int l, int r, int a)
{
	if(!p) return 0;
	if(l == r && l == a) return p -> add;
	pushDown(p);
	int mid = l + (r - l) / 2;
	if(a <= mid) return query(p -> lc, l, mid, a);
	else return query(p -> rc, mid + 1, r, a);
}

int main()
{
	freopen("environment.in", "r", stdin);
	freopen("environment.out", "w", stdout);
	scanf("%d", &m); n = 1000000000;
	root = new SegmentTree; root -> init();
	while(m--)
	{
		int op; scanf("%d", &op);
		if(op == 1)
		{
			int l, r; scanf("%d%d", &l, &r);
			l += d; r += d;
			modify(root, 0, n, l, r);
		}
		else {
			int x; scanf("%d", &x);
			printf("%d\n", d = query(root, 0, n, x));
		}
	}
	return 0;
}
