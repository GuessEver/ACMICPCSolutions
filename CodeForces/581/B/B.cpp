#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
int n, a[N], ans[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int max = 0;
	for(int i = n; i >= 1; i--)
	{
		ans[i] = std::max(max - a[i] + 1, 0);
		if(a[i] > max) max = a[i];
	}
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}
