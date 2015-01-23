#include <cstdio>

int lucky[1010], cnt = 0;

bool ok(int x)
{
	int cc = 0;
	for(int i = 2; i <= x; i++)
	{
		if(x % i == 0)
		{
			while(x % i == 0) x /= i;
			cc++;
		}
	}
	return cc >= 3;
}

int main()
{
	int i = 1;
	while(++i)
	{
		if(ok(i))
		{
			//printf("%d ", i);
			lucky[++cnt] = i;
		}
		if(cnt == 1000) break;
	}
	int T;scanf("%d", &T);
	while(T--)
	{
		int x; scanf("%d", &x);
		printf("%d\n", lucky[x]);
	}
	return 0;
}
