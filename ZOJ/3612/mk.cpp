#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	freopen("B.in", "w", stdout);
	int T = 10;
	printf("%d\n", T);
	while(T--)
	{
		int n = rand()%5+3;
		printf("%d\n", n);
		while(n--)
		{
			int p = rand();
			if(p % 5 <= 3) printf("add %d\n", rand());
			else printf("remove %d\n", rand());
		}
	}
	return 0;
}
