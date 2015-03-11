#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 6; printf("%d\n", T);
	while(T--)
	{
		puts("");
		int C = rand()%20 + 20;
		int n = rand()%10 + 10;
		printf("%d %d\n", C, n);
		for(int i = 1; i <= n; i++)
		{
			int x = rand()%20 - rand()%10;
			int y = rand()%20 - rand()%10;
			int w = rand()%10 + 1;
			printf("%d %d %d\n", x, y, w);
		}
	}
	return 0;
}
