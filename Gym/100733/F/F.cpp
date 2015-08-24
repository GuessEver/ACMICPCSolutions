#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;

int n;
struct Node{
	int d, v, t;
}a[N];
int days[N], m;
long long dp[N];
long long val[N*4];

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int mid = l + (r - l) / 2;
	long long res1 = 0, res2 = 0;
	if(a <= mid) res1 = query(p*2, l, mid, a, b);
	if(b > mid) res2 = query(p*2+1, mid+1, r, a, b);
	return std::max(res1, res2);
}
void update(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p] = c;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) update(p*2, l, mid, a, c);
	else update(p*2+1, mid+1, r, a, c);
	val[p] = std::max(val[p*2], val[p*2+1]);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &a[i].d, &a[i].v, &a[i].t);
		days[i] = a[i].d;
	}
	std::sort(days + 1, days + 1 + n);
	m = std::unique(days + 1, days + 1 + n) - days - 1;
	for(int i = 1; i <= n; i++)
	{ // i <= D && D - i <= Ti
		int pos = std::lower_bound(days + 1, days + m + 1, a[i].d - a[i].t) - days;
		int D = std::lower_bound(days + 1, days + m + 1, a[i].d) - days;
		dp[D] = query(1, 1, m, pos, D) + a[i].v;
		update(1, 1, m, D, dp[D]);
	}
	long long res = 0;
	for(int i = 1; i <= m; i++) res = std::max(res, dp[i]);
	printf("%lld\n", res);
	return 0;
}
