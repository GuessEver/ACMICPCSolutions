#include <cstdio>
#include <cstring>

long long n, k;
char ans[100], tmp[100];

void solve(long long m)
{
	//printf("## %lld <= x < %lld\n", m, m * 10);
	long long res = m + (m % k == 0 ? 0 : k - m % k);
	if(res < k || res > n) return;
	sprintf(tmp, "%I64d", res);
	if(!strcmp(ans, "") || strcmp(tmp, ans) < 0)
		strcpy(ans, tmp);
}

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	while(scanf("%I64d%I64d", &n, &k) == 2)
	{
		memset(ans, 0, sizeof(ans));
		if(n == 0 && k == 0) break;
		long long m = 1;
		while(m <= n)
		{
			solve(m);
			m *= 10;
		}
		puts(ans);
	}
	return 0;
}
