#include <cstdio>

bool check(int i)
{
	while(i)
	{
		if(i % 10 != 4 && i % 10 != 7) return 0;
		i /= 10;
	}
	return 1;
}

int main()
{
	freopen("B.out", "w", stdout);
	for(int i = 1; i <= 1000000000; i++)
	{
		if(check(i)) printf("%d, ", i);
		//if(i % 100 == 0) puts("");
		if(i % 1000000 == 0)
			fprintf(stderr, "%.3lf\n", i / 1000000000.0 * 100);
	}
	return 0;
}
