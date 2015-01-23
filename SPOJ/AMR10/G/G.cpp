#include <cstdio>
#include <algorithm>

int n, k;
long long a[20000+10];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		std::sort(a+1, a+1+n);
		long long max = 0x3f3f3f3f;
		for(int i = 1; i <= n-k+1; i++)
		{
			if(a[i+k-1] - a[i] < max) max = a[i+k-1] - a[i];
		}
		printf("%lld\n", max);
	}
	return 0;
}
