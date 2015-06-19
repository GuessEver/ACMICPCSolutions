#include <cstdio>

int a[200][200];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for(int x = x1; x <= x2; x++)
			for(int y = y1; y <= y2; y++)
				a[x][y]++;
	}
	int res = 0;
	for(int i = 1; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			res += a[i][j];
	printf("%d\n", res);
	return 0;
}
