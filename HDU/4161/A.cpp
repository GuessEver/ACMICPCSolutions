#include <cstdio>
#include <cstdlib>

int n;
long long a[1010][30];

bool check(long long *b)
{
	for(int i = 2; i <= n; i++)
		if(b[i] != b[i-1]) return 0;
	return 1;
}

int solve()
{
	if(check(a[0])) return 0;
	for(int t = 1; t <= 1000; t++)
	{
		for(int i = 1; i <= n; i++)
		{
			int k = i == n ? 1 : i + 1;
			a[t][i] = abs(a[t-1][i] - a[t-1][k]);
		}
		if(check(a[t])) return t;
	}
	return -1;
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) scanf("%lld", &a[0][i]);
		int cc = solve();
		if(cc == -1) printf("Case %d: not attained\n", ++cas);
		else printf("Case %d: %d iterations\n", ++cas, cc);
	}
	return 0;
}
