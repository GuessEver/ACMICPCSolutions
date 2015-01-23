#include <cstdio>

long long g[50];
long long f[50];
int idx = 0;
int pri[300000+10], Cnt = 0;
bool flag[300000+10];

void make_prime_list(int maxp)
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!flag[i]) pri[Cnt++] = i;
		for(int j = 0; j < Cnt && pri[j]*i <= maxp; j++)
		{
			flag[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int calc(int g)
{
	for(idx; idx < Cnt; idx++)
		if(pri[idx] > g) break;
	return --idx;
}

int main()
{
	make_prime_list(300000);
	g[0] = g[1] = g[2] = g[3] = 1;
	f[0] = f[1] = f[2] = f[3] = 0;
	for(int i = 4; i <= 40; i++)
	{
		g[i] = g[i-1] + g[i-4];
		//printf("g[%d] = %lld\n", i, g[i]);
		//g[40] = 217286
		f[i] = calc(g[i])+1;
	}
	int T; scanf("%d", &T);
	while(T--)
	{
		int n; scanf("%d", &n);
		printf("%lld\n", f[n]);
	}
	return 0;
}
