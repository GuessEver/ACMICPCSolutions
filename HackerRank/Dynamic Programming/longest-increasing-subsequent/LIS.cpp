#include <cstdio>
#include <cstring>

const int N = 1000000 + 10;
int n, a[N], c[N], f[N];

int find(int l, int r, int x)
{
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(x > c[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int len = 0;
	for(int i = 1; i <= n; i++)
	{
		int k = find(1, len, a[i]);
		c[k] = a[i];
		if(k > len) len = k;
	}
	printf("%d\n", len);
	return 0;
}
