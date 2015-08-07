#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 1000000;
	printf("%d\n", n);
	for(int i = 1; i <= n/4; i++) printf("1 2 2 2 ");
	return 0;
}
