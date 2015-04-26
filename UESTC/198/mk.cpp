#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int N = 10000;
	int T = 3; printf("%d\n", T);
	while(T--)
	{
		int m = 50 + rand()%100;
		printf("%d\n", m--);
		while(m--)
		{
			char op = rand()%100 > 50 ? 'R' : 'Q';
			if(op == 'Q')
			{
				int l = rand() % N + 1;
				int r = rand() % N + l;
				printf("Q %d %d\n", l, r);
			}
			else{
				int num = rand()%3 + 3; 
				num = 3;
				printf("R %d\n", num);
				if(num == 3)
				{
					int x1 = 1 + rand() % N - rand() % (N / 2), y1 = 1 + rand() % N - rand() % (N / 2);
					int x2 = x1+ rand() % N, y2 = y1- rand() % N;
					int x3 = x2+ rand() % N, y3 = y1+ rand() % N;
					printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
				}
				else if(num == 4)
				{
				}
				else {
				}
			}
		}
		puts("Q 1 1000000");
	}
	return 0;
}
