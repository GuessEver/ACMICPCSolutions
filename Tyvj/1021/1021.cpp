#include <cstdio>
#include <algorithm>
const int N = 10000 + 10;
int n, a[N];

int main()
{
	freopen("1021.in", "r", stdin);
	freopen("1021.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+1+n);
	long long res = 0;
	for(int i = 1; i < n; i++)
	{
		int leng = a[i+1] - a[i];
		res += (long long)i * (n-i) * leng;
	}
	printf("%lld\n", res * 2);
	return 0;
}
