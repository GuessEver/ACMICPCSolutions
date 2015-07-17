#include <cstdio>

int n;

int main()
{
	scanf("%d", &n);
	int total = 0;
	int now = 0;
	int i = 0;
	while(1)
	{
		now += i+1;
		total += now;
		if(total <= n) i++;
		else break;
	}
	printf("%d\n", i);
	return 0;
}
