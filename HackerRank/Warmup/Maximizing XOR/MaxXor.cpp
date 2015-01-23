#include <cstdio>

int main()
{
	int l, r;
	scanf("%d%d", &l, &r);
	int res = 0;
	for(int i = l; i <= r; i++)
		for(int j = l; j <= r; j++)
		{
			int tmp = i ^ j;
			if(tmp > res) res = tmp;
		}
	printf("%d\n", res);
	return 0;
}
