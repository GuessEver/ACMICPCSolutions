#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		long long ans = 1;
		int n; scanf("%d", &n);
		for(int i = 1; i <= n/2; i++)
		{
			ans *= 2;
			ans++;
		}
		if(n & 1) ans *= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
