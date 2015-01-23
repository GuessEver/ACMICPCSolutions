#include <cstdio>

int n, m, k;
int a[1010][50];

void deal(int x, int *d)
{
	for(int i = 0; i <= n; i++)
	{
		d[i] = x & 1;
		x >>= 1;
	}
}

int calc(int *d1, int *d2)
{
	int res = 0;
	for(int i = 0; i <= n; i++)
		res += (d1[i] != d2[i]);
	return res;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m+1; i++)
	{
		int x; scanf("%d", &x);
		deal(x, a[i]);
	}
	int res = 0;
	for(int i = 1; i <= m; i++)
		if(calc(a[i], a[m+1]) <= k) res++;
	printf("%d\n", res);
	return 0;
}
