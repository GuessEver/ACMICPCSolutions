#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 10;
	while(T--)
	{
		int n = 5000;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) printf("%d ", rand()%500+1); puts("");
		for(int i = 1; i <= n; i++) printf("%d ", rand()%500+1); puts("");
	}
	return 0;
}
