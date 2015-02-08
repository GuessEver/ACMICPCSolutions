#include <cstdio>
#include <cstdlib>

const int N = 100000 + 10;

int n, q, col[N*4];
long long val[N*4];
long long add[N*4];

void DOWN(int &p, int &l, int &m, int &r)
{
	if(col[p] != -1)
	{
		col[p*2] = col[p*2+1] = col[p];
		col[p] = -1;
	}
	if(add[p])
	{
		long long tmp = add[p] / (r - l + 1);
		int left = m - l + 1;
		int right = r - (m + 1) + 1;
		add[p*2] += tmp * left;
		add[p*2+1] += tmp * right;
		add[p] = 0;
	}
}
void UP(int &p)
{
	if(col[p*2] == col[p*2+1] && col[p*2] != -1) col[p] = col[p*2];
	val[p] = val[p*2] + val[p*2+1] + add[p*2] + add[p*2+1];
}

void init(int p, int l, int r)
{
	if(l == r)
	{
		col[p] = l;
		return;
	}
	col[p] = -1;
	int m = (l + r) / 2;
	init(p*2, l, m);
	init(p*2+1, m+1, r);
}

void update(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
		if(col[p] != -1)
		{
			add[p] += (r - l + 1ll) * abs(col[p] - c);
			col[p] = c;
			if(l == r)
			{
				val[p] += add[p];
				add[p] = 0;
			}
			return;
		}
	int m = (l + r) / 2;
	DOWN(p, l, m, r);
	if(a <= m) update(p*2, l, m, a, b, c);
	if(b > m) update(p*2+1, m+1, r, a, b, c);
	UP(p);
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p] + add[p];
	int m = (l + r) / 2;
	DOWN(p, l, m, r);
	long long x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	UP(p);
	return x1 + x2;
}

int main()
{
	scanf("%d%d", &n, &q);
	init(1, 1, n);
	//for(int i = 1; i <= 15; i++) printf("%d ", col[i]); puts("");
	//for(int i = 1; i <= 15; i++) printf("%lld ", val[i]); puts("");
	while(q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
		{
			int z; scanf("%d", &z);
			update(1, 1, n, x, y, z);
	//for(int i = 1; i <= 15; i++) printf("%d ", col[i]); puts("");
	//for(int i = 1; i <= 15; i++) printf("%lld ", val[i]); puts("");
		}
		else{
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
