#include <cstdio>
#include <cstdlib>

int main()
{
	int n; scanf("%d", &n);
	if(n < 4) puts("NO");
	else if(n % 4 == 0)
	{
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		int ans = 24, sign = -1;
		for(int i = 5; i <= n; i++)
		{
			char op = sign == 1 ? '+' : '-';
			printf("%d %c %d = %d\n", ans, op, i, ans + i * sign);
			ans += i * sign;
			sign = -sign;
			if(i % 2 == 0) sign = -sign;
		}
	}
	else if(n % 2 == 0)
	{
		puts("YES");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		int ans = 24, sign = -1;
		for(int i = 5; i <= n; i++)
		{
			char op = sign == 1 ? '+' : '-';
			printf("%d %c %d = %d\n", ans, op, i, ans + i * sign);
			ans += i * sign;
			sign = -sign;
			if(i % 2 == 0) sign = -sign;
		}
		sign = -sign;
		char op = sign == 1 ? '+' : '-';
		printf("%d %c %d = %d\n", ans, op, 1, ans + sign);
	}
	else if((n - 1) % 4 == 0)
	{
		puts("YES");
		puts("4 * 5 = 20");
		puts("20 + 3 = 23");
		puts("23 + 2 = 25");
		puts("25 - 1 = 24");
		int ans = 24, sign = -1;
		for(int i = 6; i <= n; i++)
		{
			char op = sign == 1 ? '+' : '-';
			printf("%d %c %d = %d\n", ans, op, i, ans + i * sign);
			ans += i * sign;
			sign = -sign;
			if((i-1) % 2 == 0) sign = -sign;
		}
	}
	else if((n - 1) % 2 == 0)
	{
		puts("YES");
		puts("6 * 7 = 42");
		puts("4 * 5 = 20");
		puts("42 - 20 = 22");
		puts("22 + 3 = 25");
		puts("25 - 2 = 23");
		puts("23 + 1 = 24");
		int ans = 24, sign = -1;
		for(int i = 8; i <= n; i++)
		{
			char op = sign == 1 ? '+' : '-';
			printf("%d %c %d = %d\n", ans, op, i, ans + i * sign);
			ans += i * sign;
			sign = -sign;
			if((i-1) % 2 == 0) sign = -sign;
		}
	}
	return 0;
}
