#include <cstdio>

int n, sum, maxx;

int calc(int rope)
{
	if(sum * 2 > rope) return 0;
	return rope / maxx + 1;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		scanf("%d", &maxx);
		sum = maxx;
		for(int i = 1; i < n; i++)
		{
			int x; scanf("%d", &x);
			if(x > maxx) maxx = x;
			sum += x;
		}
		for(int i = 50; i <=70; i += 10)
		{
			printf("%d", calc(i));
			printf("%c", i == 70 ? '\n' : ' ');
		}
	}
	return 0;
}
