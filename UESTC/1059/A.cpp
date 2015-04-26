#include <cstdio>
#include <algorithm>

const int M = 100000 * 3 + 10;

int n, m;
struct Query{ int op, l, r, c; }q[M];
int p[M], num = 0;
long long add[M*4];

int getID(int x)
{
	return std::lower_bound(p + 1, p + num + 1, x) - p;
}

void change(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		add[p] += c;
		return;
	}
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int mid = l + (r - l) / 2;
	if(a <= mid) change(p*2, l, mid, a, b, c);
	if(b > mid) change(p*2+1, mid+1, r, a, b, c);
}

long long query(int p, int l, int r, int a)
{
	if(l == r && l == a) return add[p];
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int mid = l + (r - l) / 2;
	if(a <= mid) return query(p*2, l, mid, a);
	else return query(p*2+1, mid+1, r, a);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &q[i].op, &q[i].l);
		p[++num] = q[i].l;
		if(q[i].op == 0)
		{
			scanf("%d%d", &q[i].r, &q[i].c);
			p[++num] = q[i].r;
		}
	}
	std::sort(p + 1, p + num + 1);
	num = std::unique(p + 1, p + num + 1) - (p + 1);
	for(int i = 1; i <= m; i++)
	{
		if(q[i].op == 0)
			change(1, 1, num, getID(q[i].l), getID(q[i].r), q[i].c);
		else printf("%lld\n", query(1, 1, num, getID(q[i].l)));
	}
	return 0;
}
