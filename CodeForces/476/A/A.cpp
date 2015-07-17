#include <cstdio>

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	int ans = -1;
	for(int y = 0; y <= n / 2; y++)
	{
		int x = n - 2 * y;
		if((x + y) % m == 0 && (ans == -1 || (x + y) < ans))
			ans = x + y;
	}
	printf("%d\n", ans);
	return 0;
}
