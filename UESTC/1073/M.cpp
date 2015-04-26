#include <cstdio>

const int N = 100000 + 10;

int n;
long long val[N*4];

void change(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p] = c;
		return;
	}
	int m = l + (r - l) / 2;
	if(a <= m) change(p*2, l, m, a, c);
	else change(p*2+1, m+1, r, a, c);
	val[p] = val[p*2] + val[p*2+1];
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int m = l + (r - l) / 2;
	long long res = 0;
	if(a <= m) res += query(p*2, l, m, a, b);
	if(b > m) res += query(p*2+1, m+1, r, a, b);
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		change(1, 1, n, i, x);
	}
	int q; scanf("%d", &q);
	while(q--)
	{
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if(op == 1) change(1, 1, n, x, y);
		else printf("%lld\n", query(1, 1, n, x, y));
	}
	return 0;
}
