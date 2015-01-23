#include <cstdio>
#include <algorithm>

int n;
int h[100010];
int a[100010];
long long f[100010];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		h[x]++;
	}
	f[1] = h[1];
	long long ans = f[1];
	for(int i = 2; i <= 100000; i++)
	{
		f[i] = std::max(f[i-1], f[i-2] + (long long)h[i] * i);
		ans = std::max(ans, f[i]);
	}
	printf("%lld\n", f[100000]);
	return 0;
}
