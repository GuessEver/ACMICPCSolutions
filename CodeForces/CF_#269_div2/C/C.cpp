#include <cstdio>

long long n;

int main()
{
	scanf("%I64d", &n);
	long long deep = 0;
	long long res = 0;
	while(++deep)
	{
		long long need = 2 * deep + 3 * (1 + deep) * deep / 2;
		if((n - need) % 3 == 0) 
		{
			res++;
			//printf("deep = %d    res = %d\n", deep, res);
		}
		if(need >= n) break;
	}
	printf("%I64d\n", res);
	return 0;
}
