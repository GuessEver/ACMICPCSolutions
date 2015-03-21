#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 10;
	while(T--)
	{
		int n = rand()%10 + 5;
		while(n--) putchar(rand()%26 + 'a');
		puts("");
	}
	return 0;
}
