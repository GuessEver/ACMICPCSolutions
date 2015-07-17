#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = rand()%300 + 1;
	int k = rand()%(n/2);
	printf("%d %d\n", n, k);
	return 0;
}
