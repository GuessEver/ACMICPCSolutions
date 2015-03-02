#include <cstdio>

bool calc(int &x, int &y)
{
	if(x >= 2 && y >= 1)
	{
		x -= 2; y -= 1;
		return 1;
	}
	return 0;
}

int solve(int x, int y)
{
	int res = 0;
	bool flag = 1;
	while(flag)
	{
		flag = 0;
		if(x >= y) flag |= calc(x, y);
		else if(x < y) flag |= calc(y, x);
		res += flag;
	}
	return res;
}

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d\n", solve(x, y));
	return 0;
}
