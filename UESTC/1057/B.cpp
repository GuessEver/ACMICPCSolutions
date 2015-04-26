#include <cstdio>

const int N = 100000 + 10;

int n;
long long val[N*4], add[N*4];

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
	int m = l + (r - l) / 2;
	if(a <= m) change(p*2, l, m, a, b, c);
	if(b > m) change(p*2+1, m+1, r, a, b, c);
	val[p] = val[p*2] + add[p*2] * (m - l + 1)
		+ val[p*2+1] + add[p*2+1] * (r - m);
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p] + add[p] * (r - l + 1);
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
		change(1, 1, n, i, i, x);
	}
	int q; scanf("%d", &q);
	while(q--)
	{
		int l, r, c; scanf("%d%d%d", &l, &r, &c);
		change(1, 1, n, l, r, c);
		printf("%lld\n", query(1, 1, n, l, r));
	}
	return 0;
}
