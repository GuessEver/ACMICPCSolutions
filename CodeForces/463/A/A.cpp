#include <cstdio>

int n, s;

int main()
{
	scanf("%d%d", &n, &s);
	int ans = -1;
	for(int i = 1; i <= n; i++)
	{
		int x, y, m = s * 100;
		scanf("%d%d", &x, &y);
		int money = x * 100 + y;
		//while(money <= m)
		if(money <= m)
		{
			int xx = money / 100;
			int yy = money % 100;
			if(yy == 0 && ans == -1) ans = 0;
			if(yy != 0 && 100 - yy > ans) ans = 100 - yy;
		//	money += x * 100 + y;
		}
	}
	printf("%d\n", ans);
	return 0;
}
