#include <cstdio>
#include <algorithm>
using std::min;

const int inf = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, m;
int minx[N*4];

void change(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		minx[p] = c;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) change(p*2, l, m, a, c);
	else change(p*2+1, m+1, r, a, c);
	minx[p] = min(minx[p*2], minx[p*2+1]);
}

int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return minx[p];
	int m = (l + r) / 2, x1 = inf, x2 = inf;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return min(x1, x2);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		int a; scanf("%d", &a);
		change(1, 0, n-1, i, a);
	}
	while(m--)
	{
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", query(1, 0, n-1, l, r));
	}
	return 0;
}
