#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		q -= p;
		if(q >= 2) res++;
	}
	printf("%d\n", res);
	return 0;
}
