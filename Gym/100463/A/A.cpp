#include <cstdio>
#include <cstring>

const int N = 1000000 + 10;

int n, a, b;
long long val[N*4];

void insert(int p, int l, int r, int a)
{
	if(l == r && l == a)
	{
		val[p]++;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) insert(p*2, l, mid, a);
	else insert(p*2+1, mid+1, r, a);
	val[p] = val[p*2] + val[p*2+1];
}

long long query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val[p];
	int mid = l + (r - l) / 2, res = 0;
	if(a <= mid) res += query(p*2, l, mid, a, b);
	if(b > mid) res += query(p*2+1, mid+1, r, a, b);
	return res;
}

int main()
{
	int cas = 0;
	while(scanf("%d%d%d", &n, &a, &b) == 3 && (n || a || b))
	{
		memset(val, 0, sizeof(val));
		long long res = 0;
		for(int i = 0; i < n; i++)
		{
			int now = (1ll * a * i + b) % n;
			res += query(1, 0, n - 1, now, n - 1);
			insert(1, 0, n - 1, now);
		}
		printf("Case %d: %I64d\n", ++cas, res);
	}
	return 0;
}
