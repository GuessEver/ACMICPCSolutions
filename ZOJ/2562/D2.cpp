#include <cstdio>

int calc(int x)
{
	int cnt = 0 ;
	for(int i = 1; i <= x; i++)
		if(x % i == 0) cnt++;
	return cnt;
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int ans = -1, best;
		for(int i = 1; i <= n; i++)
		{
			if(ans == -1 || calc(i) > best) best = calc(i), ans = i;
		//	if(calc(i) == best) printf("n = %3d\t\tcnt = %5d\t\tcurrent ans = %5d\n", i, calc(i), ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
