#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
using std::min;
using std::max;

int main()
{
	//freopen("B.in", "w", stdout);
	int T = 30, n = 100, m = 300, k = 1;
	printf("%d\n", T);
	while(T--)
	{
		printf("%d %d %d\n", n, m, k);
		for(int i = 1; i < n; i++) printf("%d ", rand()%100);
		printf("%d\n", rand()%100);
		for(int i = 1; i <= n; i++)
		{
			printf("0 %d %d\n", i, rand()%100);
		}
		for(int i = 1; i <= n; i++)
		{
			int a = rand()%(n/2)+1;
			int b = a + rand()%(n/2);
			printf("1 %d %d\n", a, b);
		}
		for(int i = 1; i <= n; i++)
		{
			int a = rand()%(n/2)+1;
			int b = a + rand()%(n/2);
			printf("2 %d %d\n", a, b);
		}
	}
	return 0;
}
