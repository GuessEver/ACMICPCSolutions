#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const int N = 10000 + 10;

struct Node{
	double l, r, k, b;
	int idx;
}a[N];
int n, num[N*4];

bool cmpl(Node a, Node b) 
{
	if(fabs(a.l - b.l) < 1e-7) return a.k > b.k;
	return a.l > b.l;
}
bool cmpr(Node a, Node b) 
{
	if(fabs(a.r - b.r) < 1e-7) return a.k < b.k;
	return a.r > b.r; 
}

void intree(int p, int l, int r, int a)
{
	if(l == r && l == a)
	{
		num[p]++;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) intree(p*2, l, m, a);
	else intree(p*2+1, m+1, r, a);
	num[p] = num[p*2] + num[p*2+1];
}
int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return num[p];
	int m = (l + r) / 2, x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return x1 + x2;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			a[i].k = 1.0 * (y2 - y1) / (x2 - x1);
			a[i].b = y2 - a[i].k * x2;
		}
		double left, right;
		scanf("%lf%lf", &left, &right);
		for(int i = 1; i <= n; i++)
		{
			a[i].l = a[i].k * left + a[i].b;
			a[i].r = a[i].k * right + a[i].b;
		}
		std::sort(a+1, a+1+n, cmpl);
		//for(int i = 1; i <= n; i++) printf("%.2lf ", a[i].l); puts("");
		//for(int i = 1; i <= n; i++) printf("%.2lf ", a[i].k); puts("");
		for(int i = 1; i <= n; i++) a[i].idx = i;
		std::sort(a+1, a+1+n, cmpr);
		//for(int i = 1; i <= n; i++) printf("%d ", a[i].idx); puts("");
		int res = 0;
		memset(num, 0, sizeof(num));
		for(int i = 1; i <= n; i++)
		{
			res += query(1, 1, n, a[i].idx, n);
			intree(1, 1, n, a[i].idx);
		}
		printf("%d\n", res);
	}
	return 0;
}
