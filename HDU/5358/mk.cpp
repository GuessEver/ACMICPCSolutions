#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 10; printf("%d\n", T);
	while(T--)
	{
		int n = rand()%500+100;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) printf("%d ", rand()%500);
		puts("");
	}
	return 0;
}
