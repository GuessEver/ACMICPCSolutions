#include <cstdio>
#include <algorithm>

int n, k, a[100100];

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+1+n);
	int res = 0x7fffffff;
	for(int i = k; i <= n; i++)
		if(a[i] - a[i-k+1] < res) res = a[i] - a[i-k+1];
	printf("%d\n", res);
	return 0;
}
