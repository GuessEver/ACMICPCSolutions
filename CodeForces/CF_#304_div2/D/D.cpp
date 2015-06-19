#include <cstdio>

int cnt[5000000+10];

int calc(int x)
{
	int res = 0;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return cnt[x / i] + 1;
	return 1;
}

int main()
{
	for(int i = 2; i <= 5000000; i++) cnt[i] = calc(i);
	//for(int i = 1; i <= 6; i++) printf("%d ", cnt[i]); puts("");
	for(int i = 2; i <= 5000000; i++) cnt[i] += cnt[i-1];
	//for(int i = 1; i <= 6; i++) printf("%d ", cnt[i]); puts("");
	int T; scanf("%d", &T);
	while(T--)
	{
		int a, b; scanf("%d%d", &a, &b);
		printf("%d\n", cnt[a] - cnt[b]);
	}
	return 0;
}
