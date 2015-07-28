#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;
const int P = 10000000;

bool nico[P+10], h[P+10];
int pri[P+10], Cnt;

void init()
{
	for(int i = 0; i <= 8; i++) nico[i] = 1;
	for(int i = 1; (1 << i) <= P; i++) nico[(1 << i)] = 1;
	for(int i = 2; i <= P; i++)
	{
		if(!h[i])
		{
			pri[Cnt++] = i;
			nico[i] = 1;
		}
		for(int j = 0; j < Cnt && pri[j] <= P / i; j++)
		{
			h[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int n, m, a[N];
int sum[N*4], val[N*4];

void modify(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val[p] = c;
		sum[p] = nico[c];
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) modify(p*2, l, mid, a, c);
	else modify(p*2+1, mid+1, r, a, c);
	sum[p] = sum[p*2] + sum[p*2+1];
	val[p] = std::max(val[p*2], val[p*2+1]);
}

int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return sum[p];
	int mid = l + (r - l) / 2, res = 0;
	if(a <= mid) res += query(p*2, l, mid, a, b);
	if(b > mid) res += query(p*2+1, mid+1, r, a, b);
	return res;
}

void insertMod(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		if(c > val[p]) return;
		if(l == r)
		{
			val[p] %= c;
			sum[p] = nico[val[p]];
			return;
		}
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) insertMod(p*2, l, mid, a, b, c);
	if(b > mid) insertMod(p*2+1, mid+1, r, a, b, c);
	sum[p] = sum[p*2] + sum[p*2+1];
	val[p] = std::max(val[p*2], val[p*2+1]);
}

int main()
{
	init();
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			modify(1, 1, n, i, a[i]);
		}
		scanf("%d", &m);
		while(m--)
		{
			int op; scanf("%d", &op);
			if(op == 1)
			{
				int l, r; scanf("%d%d", &l, &r);
				printf("%d\n", query(1, 1, n, l, r));
			}
			else if(op == 2)
			{
				int l, r, v; scanf("%d%d%d", &l, &r, &v);
				insertMod(1, 1, n, l, r, v);
			}
			else if(op == 3)
			{
				int p, v; scanf("%d%d", &p, &v);
				modify(1, 1, n, p, a[p] = v);
			}
		}
	}
	return 0;
}
