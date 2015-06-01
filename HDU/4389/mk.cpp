#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 100; printf("%d\n", T);
	while(T--)
	{
		int l = rand()%10000 + 1;
		int r = rand()%10000 + l;
		printf("%d %d\n", l, r);
	}
	return 0;
}
