#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 10;
	while(T--)
	{
		printf("%d\n", rand()%1000+1);
	}
	puts("0");
	return 0;
}
