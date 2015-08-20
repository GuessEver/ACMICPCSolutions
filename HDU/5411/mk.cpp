#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
int a[100000];

int main()
{
	srand(time(0));
	int T = 3; printf("%d\n", T);
	while(T--)
	{
		int n = rand()%10+1, m = rand()%10 + 1;
		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; i++)
		{
			int len = rand() % (n + 1);
			for(int i = 1; i <= len; i++) a[i] = rand()%n + 1;
			std::sort(a+1, a+1+len);
			len = std::unique(a+1, a+1+len) - a - 1;
			printf("%d", len);
			for(int i = 1; i <= len; i++) printf(" %d", a[i]);
			puts("");
		}
	}
	return 0;
}
