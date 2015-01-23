#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
const int inf = 0x3f3f3f3f;

int n, m;
int val[N * 4];

void change(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p] = c;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) change(p*2, l, m, a, c);
	else change(p*2+1, m+1, r, a, c);
	val[p] = std::min(val[p*2], val[p*2+1]);
}

int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int m = (l + r) / 2, x1 = inf, x2 = inf;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return std::min(x1, x2);
}

int main()
{
	freopen("1038.in", "r", stdin);
	freopen("1038.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		change(1, 1, n, i, x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d", query(1, 1, n, x, y));
		if(i != m) printf(" ");
		else printf("\n");
	}
	return 0;
}
