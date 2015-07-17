#include <cstdio>

int n, m, a, b;

int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int res = -1;
	for(int i = 0; i <= n/m+1; i++)
	{
		int x2 = i;
		int x1 = n - m * x2;
		if(x1 < 0) x1 = 0;
		int y = a * x1 + b * x2;
		if(res == -1 || y < res) res = y;
	}
	printf("%d\n", res);
	return 0;
}
