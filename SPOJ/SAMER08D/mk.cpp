#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	int T = 10;
	while(T--)
	{
		int K = rand()%5 + 1;
		printf("%d\n", K);
		int len = rand()%10 + 10;
		while(len--) putchar(rand()%26+'a');puts("");
		len = rand()%10 + 10;
		while(len--) putchar(rand()%26+'a');puts("");
	}
	return 0;
}
