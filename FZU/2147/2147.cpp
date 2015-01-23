#include <cstdio>

void solve()
{
	long long A, B;
	scanf("%I64d%I64d", &A, &B);
	int res = 0;
	while(A > B)
	{
		res++;
		A = A - (A % (A / 2 + 1));
	}
	printf("%d\n", res);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
	{
		printf("Case %d: ", i);
		solve();
	}
	return 0;
}
