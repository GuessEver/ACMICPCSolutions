#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 1000;
	while(T--)
	{
		int len = rand()%8+2;
		for(int i = 1; i <= len; i++) printf("%d", rand()%10);
		puts("");
	}
	return 0;
}
