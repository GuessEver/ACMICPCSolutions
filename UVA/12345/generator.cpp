#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 5000, m = 5000;
	printf("%d %d\n", n, m + 1);
	for(int i = 1; i <= n; i++) printf("%d ", rand()%10000 + 1); puts("");
	while(m--)
	{
		char op = rand()%100 > 50 ? 'Q' : 'M';
		if(op == 'Q')
		{
			int l = rand() % n;
			int r = rand() % (n - l) + l + 1;
			printf("Q %d %d\n", l, r);
		}
		else {
			int l = rand() % n;
			int x = rand() % 10000 + 1;
			printf("M %d %d\n", l, x);
		}
	}
	printf("Q %d %d\n", 0, n);
	return 0;
}
