#include <cstdio>

int n, m, k;
int a[1010][1010];

bool check(int x, int y)
{
	 return (a[x+1][y] && a[x+1][y+1] && a[x][y+1])
		 || (a[x-1][y] && a[x-1][y+1] && a[x][y+1])
		 || (a[x-1][y] && a[x-1][y-1] && a[x][y-1])
		 || (a[x][y-1] && a[x+1][y-1] && a[x+1][y]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		a[x][y] = 1;
		if(check(x, y))
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", 0);
	return 0;
}
