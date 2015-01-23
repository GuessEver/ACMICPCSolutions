#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	freopen("G.in", "w", stdout);
	srand(time(0));
	int t = 3;
	printf("%d\n",t);
	while(t--)
	{
		int n = rand()%5 + 4;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++)
		{
			int d = rand()%4+3;
			printf("%d", d);
			while(d--) printf(" %d", rand()%n+1);
			printf("\n");
		}
	}
	return 0;
}
