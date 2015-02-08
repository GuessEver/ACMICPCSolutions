#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 5; printf("%d\n", T);
	while(T--)
	{
		int n = rand()%20000000+80000000;
		int m = rand()%20000+80000;
		printf("%d %d\n", n, m);
		for(int i = 1; i <= m-2; i++)
		{
			int op = rand()%99;
			int x = rand()%n+1;
			if(op < 33) printf("Top %d\n", x);
			else if(op < 66) printf("Rank %d\n", x);
			else printf("Query %d\n", x);
		}
		printf("Rank %d\n", n);
		printf("Query %d\n", n);
	}
	return 0;
}
