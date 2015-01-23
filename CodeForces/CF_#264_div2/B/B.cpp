#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n;
long long a[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	a[0] = 0;
	long long cost = 0, hp = 0;
	for(int i = 1; i <= n; i++)
	{
		long long tmp = a[i] - a[i-1];
		if(tmp > 0)
		{
			long long x = std::min(hp, tmp);
			tmp -= x;
			hp -= x;
			cost += tmp;
		}
		else if(tmp < 0)
		{
			hp -= tmp;
		}
	}
	printf("%lld\n", cost);
	return 0;
}
