#include <cstdio>

const int on[20][20] = {
	{1, 0, 1, 1, 1, 1, 1}, // 0
	{0, 0, 0, 0, 0, 1, 1}, // 1
	{1, 1, 1, 0, 1, 1, 0}, // 2
	{1, 1, 1, 0, 0, 1, 1}, // 3
	{0, 1, 0, 1, 0, 1, 1}, // 4
	{1, 1, 1, 1, 0, 0, 1}, // 5
	{1, 1, 1, 1, 1, 0, 1}, // 6
	{1, 0, 0, 0, 0, 1, 1}, // 7
	{1, 1, 1, 1, 1, 1, 1}, // 8
	{1, 1, 1, 1, 0, 1, 1}, // 9
};

int main()
{
	int n; scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < 100; i++)
	{
		bool flag = 1;
		for(int k = 0; k < 7; k++)
		{
			int x1 = n / 10, x2 = n % 10;
			int y1 = i / 10, y2 = i % 10;
			if(on[x1][k] && !on[y1][k]) flag = 0;
			if(on[x2][k] && !on[y2][k]) flag = 0;
			if(flag == 0) break;
		}
		cnt += flag;
	}
	printf("%d\n", cnt);
	return 0;
}
