#include <cstdio>
#include <cstring>

int pri[50010]; bool flag[50010]; int Cnt = 0;
int num[50010];

void make_prime_list(int maxp)
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!flag[i]) pri[Cnt] = i, num[i] = Cnt++;
		for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
		{
			flag[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

long long n;
long long cc[50010];
long long ans;

int main()
{
	make_prime_list(50000);
	while(scanf("%lld", &n) == 1)
	{
		memset(cc, 0, sizeof(cc));
		int last = 0;
		ans = 1;
		while(ans <= n)
		{
			int tmp = pri[0];
			for(int i = 0; i <= last && ans * pri[i] <= n; i++)
			{
				long long a = tmp - 1, b = cc[tmp] + 1;
				long long c = pri[i] - 1, d = cc[pri[i]] + 1;
				if(a * b < c * d) ;
				else if(a * b > c * d) tmp = pri[i];
				else{
					if(cc[tmp] <= cc[pri[i]]) ;
					else tmp = pri[i];
				}
			}
			if(ans * tmp <= n) ans *= tmp;
			else break;
			cc[tmp]++;
			last = num[tmp] + 1;
			printf("ans = %lld\n", ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
