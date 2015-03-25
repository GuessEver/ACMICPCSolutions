#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 3;
	while(T--)
	{
		int n = 100; printf("%d\n", n);
		while(n--) printf("%d ", rand()%100+1); puts("");
	}
	puts("0");
	return 0;
}
