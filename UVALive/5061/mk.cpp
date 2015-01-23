#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int T = 3; printf("%d\n", T);
	while(T--)
	{
		int n = rand()%10 + 5;
		printf("%d\n", n);
		for(int i = 1; i <= n; i++)
		{
			if(i * 2 <= n) printf("%d %d\n", i-1, i*2-1);
			if(i * 2 + 1 <= n) printf("%d %d\n", i-1, i*2+1-1);
		}
		int q = rand()%10 + 5;
		printf("%d\n", q);
		while(q--)
			printf("%d %d %d\n", rand()%n, rand()%n, rand()%10+10);
	}
	return 0;
}
