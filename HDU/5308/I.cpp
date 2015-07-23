#include <cstdio>

bool solve(int n)
{
	if(n >= 14)
	{
		printf("1 + 2\n"); // n+1
		for(int i = 3; i <= 4; i++) printf("%d + %d\n", n + i - 2, i); // n+3
		printf("%d / %d\n", n + 3, 5); // -> n+4
		printf("%d + %d\n", 6, 7); // -> n+5
		for(int i = 8; i <= 11; i++) printf("%d + %d\n", n + i - 3, i); // -> n+9
		printf("%d / %d\n", n + 9, 12); // -> n+10
		printf("%d * %d\n", n+4, n+10); // -> n+11
		printf("%d - %d\n", 13, 14); // -> n+12
		for(int i = 15; i <= n; i++) printf("%d * %d\n", n + i - 3 , i);
		printf("%d + %d\n", n + 11, n + n - 2);
		return 1;
	}
	if(n <= 3) return 0;
	if(n == 4)
	{
		printf("1 * 2\n");
		printf("5 + 3\n");
		printf("6 + 4\n");
		return 1;
	}
	if(n == 5)
	{
		printf("1 * 2\n");
		printf("6 * 3\n");
		printf("7 - 4\n");
		printf("8 / 5\n");
		return 1;
	}
	if(n == 6)
	{
		printf("1 + 2\n");
		printf("7 + 3\n");
		printf("8 + 4\n");
		printf("9 + 5\n");
		printf("10 - 6\n");
		return 1;
	}
	if(n == 7)
	{
		printf("1 + 2\n"); // 8
		printf("8 + 3\n"); // 9
		printf("4 + 5\n"); // 10
		printf("10 + 6\n"); // 11
		printf("11 / 7\n"); // 12
		printf("9 + 12\n"); // 13
		return 1;
	}
	if(n == 8)
	{
		printf("1 + 2\n"); // 9
		printf("9 + 3\n"); // 10
		printf("4 + 5\n"); // 11
		printf("11 + 6\n"); // 12
		printf("7 - 8\n"); // 13
		printf("13 * 12\n"); // 14
		printf("10 + 14\n"); // 15
		return 1;
	}
	if(n == 9)
	{
		for(int i = 1; i <= 8; i += 2)
			printf("%d / %d\n", i, i+1); //10, 11, 12, 13
		printf("9 - 10\n"); // 14
		printf("11 + 12\n"); //15
		printf("15 + 13\n"); // 16
		printf("16 * 14\n"); // 17
		return 1;
	}
	if(n == 10)
	{
		printf("1 + 2\n"); // 11
		printf("3 / 4\n"); // 12
		printf("5 / 6\n"); // 13
		printf("7 / 8\n"); // 14
		printf("9 / 10\n"); // 15
		printf("11 + 12\n"); // 16
		printf("16 + 13\n"); // 17
		printf("17 + 14\n"); // 18
		printf("18 + 15\n"); // 19
		return 1;
	}
	if(n == 11)
	{
		printf("1 / 2\n"); // 12
		printf("12 + 3\n"); // 13
		printf("4 + 5\n"); // 14
		printf("14 / 6\n"); // 15
		printf("7 - 8\n"); // 16
		printf("9 + 10\n"); // 17
		printf("17 + 11\n"); // 18
		printf("16 * 18\n"); // 19
		printf("13 * 15\n"); // 20
		printf("20 + 19\n"); // 21
		return 1;
	}
	if(n == 12)
	{
		printf("1 + 2\n"); // 13
		for(int i = 3; i <= 12; )
		{
			printf("%d + %d\n", n + i - 2, i);
			i++;
			printf("%d - %d\n", n + i - 2, i);
			i++;
		}
		return 1;
	}
	if(n == 13)
	{
		printf("1 + 2\n"); // 14
		printf("14 + 3\n"); // 15
		printf("4 + 5\n"); // 16
		printf("16 + 6\n"); // 17
		printf("17 + 7\n"); // 18
		printf("18 + 8\n"); // 19
		printf("19 + 9\n"); // 20
		printf("20 + 10\n"); // 21
		printf("21 + 11\n"); // 22
		printf("15 / 12\n"); // 23
		printf("22 / 13\n"); // 24
		printf("23 * 24\n");
		return 1;
	}
}

int n;

int main()
{
	freopen("I.in", "r", stdin);
	freopen("I.out", "w", stdout);
	while(scanf("%d", &n) == 1)
		if(!solve(n)) puts("-1");
	return 0;
}
