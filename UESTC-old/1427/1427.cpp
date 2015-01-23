#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	for(int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n", cas);
		int M; scanf("%d", &M);
		if (M <= 2) 
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n4\n");
		printf("1\n2\n%d\n%d\n", M - 1, 2 * M);
	}
	return 0;
}
