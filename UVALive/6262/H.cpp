#include <cstdio>
#include <cmath>

int n;

long long calc(int x, int y)
{
	long long res = 0;
	int D2 = (x * x) + (y * y);
	int p;
	if(D2 <= 400) p = 1;
	else if(D2 <= 1600) p = 2;
	else if(D2 <= 3600) p = 3;
	else if(D2 <= 6400) p = 4;
	else if(D2 <= 10000) p = 5;
	else if(D2 <= 120 * 120) p = 6;
	else if(D2 <= 140 * 140) p = 7;
	else if(D2 <= 160 * 160) p = 8;
	else if(D2 <= 180 * 180) p = 9;
	else if(D2 <= 200 * 200) p = 10;
	else p = 11;
	return (11 - p);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		long long sum = 0;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			sum += calc(x, y);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
