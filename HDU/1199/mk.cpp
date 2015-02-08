#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = rand()%50+30;
	printf("%d\n", n);
	int m = rand()%1000+1000;
	while(n--)
	{
		int x = rand()%(m/2) + 1;
		int y = x + rand()%(m/2) + 1;
		char ch = rand()%100 > 50 ? 'w' : 'b';
		printf("%d %d %c\n", x, y, ch);
	}
	return 0;
}
