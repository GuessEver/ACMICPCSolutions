#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	freopen("H.in", "w", stdout);
	srand(time(0));
	int n = 10000, m = 100000, q = 10000;
	printf("%d %d %d\n", n, m, q);
	while(m--)
	{
		int x = rand()%n + 1;
		int y = rand()%n + 1;
		printf("%d %d\n", x, y);
	}
	while(q--)
	{
		int x = rand()%n + 1;
		int y = rand()%n + 1;
		printf("%d %d\n", x, y);
	}
	return 0;
}
