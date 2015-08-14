#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int a[10000];
int n, m, d, l;

bool check(int y, int x)
{
	for(int i = 1; i <= n; i++) if(i != x)
		if(a[i] == y) return 0;
	return 1;
}

int main()
{
	srand(time(0));
	n = 1000, m = 1000, d = 1000, l = rand()%1000+1;
	printf("%d %d %d %d\n", n, m, d, l);
	int dis = 0;
	for(int i = 2; i <= n; i++)
	{
		dis += rand()%10 + 1;
		printf("%d ", dis);
	}
	puts("");
	dis = 0;
	for(int i = 1; i <= m; i++)
	{
		dis += rand()%10 + 1;
		printf("%d ", dis);
		a[i] = dis;
	}
	puts("");
	for(int i = 1; i <= d; i++)
	{
		int x = rand()%m + 1;
		int y = rand()%20 - 10 + a[x];
		while(!check(y, x) || y < 0)
			y = rand()%20 - 10 + a[x];
		printf("%d %d\n", a[x], y);
		a[x] = y;
	}
	return 0;
}

