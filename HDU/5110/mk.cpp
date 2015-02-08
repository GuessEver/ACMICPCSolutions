#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 3;
	while(T--)
	{
		int n = rand()%50+30;
		int m = rand()%50+30;
		int q = rand()%500+500;
		printf("%d %d %d\n", n, m, q);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				putchar(rand()%100 > 80 ? '.' : 'X');
			puts("");
		}
		while(q--)
		{
			int x = rand()%n + 1;
			int y = rand()%m + 1;
			int d = rand()%n + 1;
			printf("%d %d %d\n", x, y, d);
		}
	}
	return 0;
}
