#include <cstdio>

int n;

int main()
{
	freopen("jubilee.in", "r", stdin);
	freopen("jubilee.out", "w", stdout);
	while(scanf("%d", &n) == 1 && n)
	{
		if(n == 3)
		{
			printf("1\n1 1 1\n1 1 1\n");
			continue;
		}
		else if(n == 4)
		{
			printf("2\n1 1 2 2\n1 2 1 2\n");
			continue;
		}
		else if(n == 5)
		{
			printf("2\n1 1 2 2 2\n1 2 2 1 1\n");
			continue;
		}
		else if(n == 6)
		{
			printf("2\n1 1 1 2 2 2\n1 2 1 1 2 1\n");
			continue;
		}
		else {
			printf("3\n");
			for(int i = 1, j = 1; i <= n; i++, j = 3 - j)
				printf("%d%s", j, i == n ? "\n" : " ");
			for(int i = 1; i <= n; i++)
				printf("%d%s", 3, i == n ? "\n" : " ");
		}
	}
	return 0;
}
