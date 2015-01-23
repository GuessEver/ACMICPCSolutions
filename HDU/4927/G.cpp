#include <cstdio>
#include <cstring>

int n;
long long a[3000+10];

long long C(int n, int m)
{
	long long res = 1;
	for(int i = 1; i <= m; i++) { res *= n; n--; }
	for(int i = 1; i <= m; i++) res /= i;
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		long long ans = 0;
		int sign = 1;
		for(int i = n; i >= 1; i--)
		{
			ans += a[i] * C(n-1, i-1) * sign;
			sign = -sign;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
