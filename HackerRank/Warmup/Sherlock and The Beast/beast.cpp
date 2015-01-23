#include <cstdio>

int n, x, y;

bool solve()
{
	x = -1; y = -1;
	for(int i = 0; i <= n / 3 + 1; i++)
	{
		int tmp = n - 3 * i;
		if(tmp < 0 || tmp % 5) continue;
		y = tmp; x = 3 * i;
	}
	return !(x == -1 && y == -1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		// 3x + 5y = n    And let x as max as possible
		if(!solve()) puts("-1");
		else{
			while(x--) putchar('5');
			while(y--) putchar('3');
			puts("");
		}
	}
	return 0;
}
