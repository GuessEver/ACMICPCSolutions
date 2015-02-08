#include <cstdio>

int main()
{
	int T = 1;
	printf("%d\n", T);
	while(T--)
	{
		int n = 30000, k = 30000;
		printf("%d %d\n", n, k);
		for(int i = 1; i <= n; i++)
			printf("%d %d %d %d\n", 0, 0, i, i);
	}
	return 0;
}
