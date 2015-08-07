#include <cstdio>

int calc(int x)
{
	int y = x;
	int cnt = 0;
	while(x)
	{
		cnt += x & 1;
		x >>= 1;
	}
	return y % cnt == 0;
}

void P(int x)
{
	if(x == 0) return;
	P(x >> 1);
	printf("%1d", x & 1);
}

int main()
{
	long long sum = 0;
	long long n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
	{
		int tmp = calc(i);
		if(tmp)
		{
			sum += tmp;
			//printf("%d ", i);
			//P(i);
			//printf(" %lld\n", sum);
		}
	}
	printf("%lld\n", sum);
	return 0;
}
