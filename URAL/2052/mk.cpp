#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = rand()%1000000 + 1;
	printf("%d\n", n);
	return 0;
}
