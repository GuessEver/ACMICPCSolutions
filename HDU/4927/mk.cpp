#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 3;
	printf("%d\n", T);
	while(T--)
	{
		int n = 3 + rand()%5; printf("%d\n", n);
		for(int i = 1; i <= n; i++) printf("%d ", rand()%10);
		puts("");
	}
	return 0;
}
