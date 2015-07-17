#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, m, k;
struct segment_tree{
	int val[N * 4];
	void init(int p, int l, int r, int a, int c)
	{
		if(l == r && l == a)
		{
			val[p] = c;
			return;
		}
		int m = l + (r - l) / 2;
		if(a <= m) init(p*2, l, m, a, c);
		else init(p*2+1, m+1, r, a, c);
		val[p] = std::max(val[p*2], val[p*2+1]);
	}
	int getmax(int p, int l, int r, int a, int b)
	{
		if(a <= l && b >= r) return val[p];
		int m = l + (r - l) / 2, x1 = 0, x2 = 0;
		if(a <= m) x1 = getmax(p*2, l, m, a, b);
		if(b > m) x2 = getmax(p*2+1, m+1, r, a, b);
		return std::max(x1, x2);
	}
}seg[10];
int ans[10], now[10];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x; scanf("%d", &x);
			seg[j].init(1, 1, n, i, x);
		}
	int l = 1, r = 1, maxlen = 0; // [l, r)
	while(l <= n && r <= n)
	{
		int sum = 0;
		for(int j = 1; j <= m; j++)
		{
			now[j] = seg[j].getmax(1, 1, n, l, r);
			sum += now[j];
		}
		if(sum > k) { l++; r++; }
		else{
			if(r - l + 1 > maxlen)
			{
				maxlen = r - l + 1;
				for(int j = 1; j <= m; j++)
					ans[j] = now[j];
			}
			r++;
		}
	}
	//printf("%d\n", maxlen);
	for(int j = 1; j < m; j++) printf("%d ", ans[j]);
	printf("%d\n", ans[m]);
	return 0;
}
