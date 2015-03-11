#include <cstdio>
#include <cstring>

const int N = 250 * 250 + 10;

int n, p, q;
int a[N], b[N], c[N];

int LIS(int n)
{
	int len = 0;
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = len;
		while(l <= r)
		{
			int mid = l + (r - l) / 2;
			if(a[i] > c[mid]) l = mid + 1;
			else r = mid - 1;
		}
		c[l] = a[i];
		if(l > len) len = l;
	}
	return len;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &n, &p, &q);
		p++; q++;
		for(int i = 1; i <= p; i++) scanf("%d", &a[i]);
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= q; i++)
		{
			int x; scanf("%d", &x);
			b[x] = i;
		}
		for(int i = 1; i <= p; i++) a[i] = b[a[i]];
		//for(int i = 1; i <= p; i++) printf("%d ", a[i]); puts("");
		printf("Case %d: %d\n", cas, LIS(p));
	}
	return 0;
}
