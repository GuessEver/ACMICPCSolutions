#include <cstdio>

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	int day = 0;
	while(1)
	{
		if(day && day % m == 0) n++;
		n--;
		if(n < 0) break;
		day++;
	}
	printf("%d\n", day);
	return 0;
}
