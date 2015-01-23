#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = rand()%10000 + 10000;
	int x = rand()%10000 + 10000;
	int y = rand()%10000 + 10000;
	printf("%d %d %d\n", n, x, y);
	for(int i = 1; i <= n; i++)
		printf("%d\n", rand()%10000000 + 10000000);
	return 0;
}
