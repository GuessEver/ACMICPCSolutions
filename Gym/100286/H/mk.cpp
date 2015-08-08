#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	freopen("hell.in", "w", stdout);
	int n = 15;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++)
		printf("%d ", rand()%i+1);
	return 0;
}
