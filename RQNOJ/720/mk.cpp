#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int main()
{
	freopen("A.in", "w", stdout);
	srand(time(0));
	int n = 70, q = 500;
	printf("%d %d\n", n, q);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			printf("%d ", rand()%100);
		}
		printf("\n");
	}
	while(q--)
	{
		int op = rand()%3;
		int x = rand()%n + 1;
		int y = rand()%n + 1;
		if(op == 1) printf("A");
		else if(op == 2) printf("C");
		else printf("R");
		printf(" %d %d\n", x, y);
	}
	return 0;
}
