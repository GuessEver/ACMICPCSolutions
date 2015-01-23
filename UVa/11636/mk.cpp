#include <cstdio>
#include <ctime>
#include <cstdlib>

int main()
{
	srand(time(0));
	freopen("11636.in", "w", stdout);
	int t = 1000;
	for(int i=1; i <= t; i++)
		printf("%d\n", rand()%1000+1);
	printf("-1\n");
	return 0;
}
