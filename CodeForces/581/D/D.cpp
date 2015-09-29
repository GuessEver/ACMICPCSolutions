#include <cstdio>

bool check1(int x1, int y1, int x2, int y2, int x3, int y3, char A, char B, char C)
{
	if(y1 == y2 && y2 == y3 && x1 + x2 + x3 == y1)
	{
		printf("%d\n", y1);
		for(int y = 1; y <= y1; y++)
		{
			for(int x = 1; x <= x1; x++) putchar(A);
			for(int x = 1; x <= x2; x++) putchar(B);
			for(int x = 1; x <= x3; x++) putchar(C);
			puts("");
		}
		return 1;
	}
	return 0;
}
bool check2(int x1, int y1, int x2, int y2, int x3, int y3, char A, char B, char C)
{
	if(x2 + x3 == x1 && y2 == y3 && y1 + y2 == x1)
	{
		printf("%d\n", x1);
		for(int y = 1; y <= y1; y++)
		{
			for(int x = 1; x <= x1; x++) putchar(A);
			puts("");
		}
		for(int y = 1; y <= y2; y++)
		{
			for(int x = 1; x <= x2; x++) putchar(B);
			for(int x = 1; x <= x3; x++) putchar(C);
			puts("");
		}
		return 1;
	}
	return 0;
}
int p[5][2];
bool check(int i, int j, int k)
{
	char A = i + 'A' - 1;
	char B = j + 'A' - 1;
	char C = k + 'A' - 1;
	for(int S = 0; S < 8; S++)
	{
		bool tmp1 = S & 1, tmp2 = S & 2, tmp3 = S & 4;
		if(check1(p[i][tmp1], p[i][1-tmp1], p[j][tmp2], p[j][1-tmp2], p[k][tmp3], p[k][1-tmp3], A, B, C)
				|| check2(p[i][tmp1], p[i][1-tmp1], p[j][tmp2], p[j][1-tmp2], p[k][tmp3], p[k][1-tmp3], A, B, C)) return 1;
	}
	return 0;
}
int main()
{
	for(int i = 1; i <= 3; i++)
		for(int j = 0; j < 2; j++) scanf("%d", &p[i][j]);
	if(check(1, 2, 3) || check(1, 3, 2)
			|| check(2, 1, 3) || check(2, 3, 1)
			|| check(3, 1, 2) || check(3, 2, 1)) return 0;
	puts("-1");
	return 0;
}
