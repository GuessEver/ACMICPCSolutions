#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Node{
	int x, y;
	int ord;
	bool operator < (const Node &b) const
	{
		return ord < b.ord;
	}
}a[100000+10];

int main()
{
	srand(time(0));
	int n = rand()%30000+20000;
	int m = rand()%30000+20000;
	printf("%d\n", n+m);
	for(int i = 1; i <= n; i++)
	{
		a[i].x = a[i-1].x + rand()%10+1;
		a[i].y = a[i-1].y + rand()%10+1;
		a[i].ord = rand()%(n+m);
	}
	m += n;
	for(int i = n + 1; i <= m; i++)
	{
		a[i].x = rand()%100;
		a[i].y = rand()%100;
		a[i].ord = rand()%m;
	}
	std::sort(a+1, a+1+m);
	for(int i = 1; i <= m; i++)
		printf("%d %d\n", a[i].x, a[i].y);
	return 0;
}
