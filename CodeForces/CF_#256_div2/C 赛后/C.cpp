#include <cstdio>
#include <algorithm>

int n, a[5000+10];

int calc(int l, int r, int h)
{
	if(l > r) return 0;
	int k = l;
	for(int i = l; i <= r; i++)
		if(a[i] < a[k]) k = i;
	int res1 = r - l + 1;
	int res2 = calc(l, k-1, a[k]) + calc(k+1, r, a[k]) + a[k] - h;
	return std::min(res1, res2);
}

int main()
{
	//freopen("C.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", calc(1, n, 0));
	return 0;
}
