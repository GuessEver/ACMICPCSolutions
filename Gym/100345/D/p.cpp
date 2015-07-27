#include <cstdio>

bool check(int x)
{
	int a[10] = {0};
	while(x)
	{
		int tmp = x % 10; x/= 10;
		if(a[tmp] >= 2) return 0;
		a[tmp]++;
	}
	return 1;
}

int main()
{
	int l, r; scanf("%d%d", &l, &r);
	int cnt = 0;
	for(int i = l; i <= r; i++)
	{
		if(check(i))
		{
	//		printf("%d, ", i);
			cnt++;
		}
	}
	printf("\ncnt = %d\n", cnt);
	return 0;
}
