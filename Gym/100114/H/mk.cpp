#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 1000, m = 200;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; i++) printf("%d ", rand()%200+1);
	puts("");
	while(m--)
	{
		int l = rand()%(n / 2) + 1;
		int r = rand()%(n / 2) + l;
		printf("%d %d\n", l, r);
	}
	return 0;
}
