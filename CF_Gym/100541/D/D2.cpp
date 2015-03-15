#include <cstdio>

long long n, k;

int find(int x)
{
	int l = 1, r = 7;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(x * (1 << mid) < 100) l = mid + 1;
		else r = mid;
	}
	return l;
}

long long solve()
{
	while(k)
	{
		int x = n % 100; n -= x;
		if(x == 0) return n;
		int tmp = find(x);
		if(tmp > k) tmp = k;
		k -= tmp; x *= (1 << tmp);
		n += x;
	}
	return n;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &n, &k);
		printf("%lld\n", solve());
	}
	return 0;
}
