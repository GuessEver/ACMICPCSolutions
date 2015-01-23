#include <cstdio>

int main()
{
	int x, sum = 0;
	for(int i = 1; i <= 5; i++)
	{
		scanf("%d", &x);
		sum += x;
	}
	if(sum % 5 == 0 && sum / 5 > 0) printf("%d\n", sum / 5);
	else puts("-1");
	return 0;
}
