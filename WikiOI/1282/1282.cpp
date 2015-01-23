#include <cstdio>

const int N = 30000 + 10;
int n, m;
int sum[N*4];
int ans;

void init_tree(int p, int l, int r)
{
	if(l == r)
	{
		sum[p] = 1;
		return;
	}
	int m = (l + r) / 2;
	init_tree(p*2, l, m);
	init_tree(p*2+1, m+1, r);
	sum[p] = sum[p*2] + sum[p*2+1];
}

int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return sum[p];
	int m = (l + r) / 2, x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return x1 + x2;
}

void del(int p, int l, int r, int a)
{
	if(l == r)
	{
		ans = l;
		sum[p] = 0;
		return;
	}
	int m = (l + r) / 2;
	if(sum[p*2] >= a) del(p*2, l, m, a);
	else del(p*2+1, m+1, r, a-sum[p*2]);
	sum[p] = sum[p*2] + sum[p*2+1];
}

int main()
{
	freopen("1282.in", "r", stdin);
	freopen("1282.out", "w", stdout);
	scanf("%d%d", &n, &m);
	init_tree(1, 1, n);
	int pos = 0, left = n + 1;
	for(int i = 1; i <= n; i++)
	{
		left--;
		int front = 0;
		if(ans > 1) front = query(1, 1, n, 1, ans-1);
		pos = (front + m) % left;
		if(pos == 0) pos = left;
		del(1, 1, n, pos);
		printf("%d", ans);
		if(i < n) printf(" ");
	}
	printf("\n");
	return 0;
}
