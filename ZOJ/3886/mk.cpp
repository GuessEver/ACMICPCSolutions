#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 10000;
	printf("%d\n", n);
	for(int i = 1; i <= n; i++) printf("%d ", rand()%10000+3); puts("");
	int m = 10000;
	printf("%d\n", m);
	while(m--)
	{
		int op = rand()%3+1;
		if(op == 1)
		{
			int l = rand()%(n / 2) + 1;
			int r = rand()%(n / 2) + l;
			//l = 1, r = n;
			printf("1 %d %d\n", l, r);
		}
		else if(op == 2)
		{
			int l = rand()%(n / 2) + 1;
			int r = rand()%(n / 2) + l;
			//l = 1, r = n;
			int v = rand()%100000 + 1;
			//v = 1;
			printf("2 %d %d %d\n", l, r, v);
		}
		else {
			int p = rand()%n + 1;
			int v = rand()%10000 + 1;
			printf("3 %d %d\n", p, v);
		}
	}
	return 0;
}
