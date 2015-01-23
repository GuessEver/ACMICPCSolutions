#include <cstdio>
const int N = 5000 + 10;

int n;
int flag[50000+10], pri[50000+10], Cnt;
int ans = 1, maxp = 0;

void make_prime_list(int m)
{
	for(int i = 2; i <= m; i++)
	{
		if(!flag[i]) pri[Cnt++] = i;
		for(int j = 0; j < Cnt && i * pri[j] <= m; j++)
		{
			flag[i*pri[j]] = 1;
			if(i % pri[j]) break;
		}
	}
}

void solve(int x)
{
	int j = 0, oldx = x;
	while(j<Cnt && x != 1)
	{
		if(x % pri[j] != 0) goto end;
		while(x % pri[j] == 0) x /= pri[j];
		if(j > maxp) maxp = j, ans = oldx;
		end:; j++;
	}
}

int main()
{
	freopen("1020.in", "r", stdin);
	freopen("1020.out", "w", stdout);
	make_prime_list(50000);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		solve(x);
	}
	printf("%d\n", ans);
	return 0;
}
