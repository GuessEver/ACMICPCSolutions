#include <cstdio>
const int N = 40000 + 10;

int n, m, a[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		long long sum = 0;
		int max = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if(a[i] > max) max = a[i];
			sum += a[i];
		}
		if(max > (sum+m-1)/m) printf("%d\n", max);
		else printf("%lld\n", (sum+m-1)/m);
	}
	return 0;
}
