#include <cstdio>

long long A(int x)
{
	long long res = 1;
	for(int i = 2; i <= x; i++) res *= i;
	return res;
}
long long C(int n, int m)
{
	return A(n) / A(n-m) / A(m);
}

long long cal(int x, int m)
{
	if(m == 0) return A(x);
	long long res = A(x);
	for(int i = 1; i <= m; i++)
	{
		res -= C(m, m-i) * cal(x-i, m-i);
	}
	return res;
}

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	long long res = cal(n, k);
	printf("%lld\n", res);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		solve();
	}
	return 0;
}
