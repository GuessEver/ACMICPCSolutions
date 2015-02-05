#include <cstdio>

int n;

int solve(int m, int now, int sum, int pro)
{
	int res = 0;
	for(int i = now; i > 1; i--)
	{
		if(sum + i*m < pro * i) break;
		if(sum + i + (m-1) == pro * i)
			res++;
		else res += solve(m-1, i, sum+i, pro*i);
	}
	return res;
}

int main()
{
	freopen("sump.in", "r", stdin);
	freopen("sump.out", "w", stdout);
	scanf("%d", &n);
	printf("%d\n", solve(n, n, 0, 1));
	return 0;
}
