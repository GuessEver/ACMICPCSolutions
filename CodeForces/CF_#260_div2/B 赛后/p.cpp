#include <cstdio>

int main()
{
	for(int n = 1; n <= 100; n++)
	{
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int tmp = 1;
			for(int j = 1; j <= n; j++)
				tmp = tmp % 5 * i % 5;
			ans += tmp;
			ans %= 5;
		}
		printf("%d ", ans % 5);
	}
	return 0;
}
