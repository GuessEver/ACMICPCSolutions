#include <cstdlib>
#include <cstdio>
#include <ctime>

int main()
{
	srand(time(0));
	int n = rand()%5000+5000;
	int m = rand()%5000+5000;
	printf("%d %d\n", n, m);
	while(m--)
	{
		int op = rand()%100;
		int x = rand()%(n/2)+1;
		int y = rand()%(n/2) + x;
		int z = rand()%n+1;
		if(op < 60) printf("%d %d %d %d\n", 1, x, y, z);
		else printf("%d %d %d\n", 2, x, y);
	}
	return 0;
}
