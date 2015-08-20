#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
	srand(time(0));
	int T = 10; printf("%d\n", T);
	while(T--)
	{
		int n = rand()%100 + 1;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++)
			printf("%d %d\n", rand()%100+1, rand()%100+1);
	}
	return 0;
}
