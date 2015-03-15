#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 5; printf("%d\n", T);
	while(T--)
	{
		int n = 10, m = 20;
		printf("%d %d\n", n, m);
		for(int i = 1; i < m; i++)
		{
			int op = rand()%2;
			int x = rand()%(n / 2) + 1;
			int y = rand()%(n / 2) + x;
			int p = rand()%10+1;
			if(op == 0) p = 1000000007;
			printf("%d %d %d %d\n", op, x, y, p);
		}
		printf("0 %d %d %d\n", 1, n, 1000000007);
	}
}
