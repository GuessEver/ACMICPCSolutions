#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = (1 << 15) + 10;

int n, a[20];
int tot;
int cnt[N];
bool f[110][N], vis[110][N];
int sum[N];

int getSum(int S)
{
	int res = 0, st = S;
	for(int i = 0; i < n; i++)
	{
		res += (S & 1) * a[i];
		cnt[st] += (S & 1);
		S >>= 1;
	}
	return res;
}

bool solve(int x, int S)
{
	if(cnt[S] == 1) return 1;
	if(vis[x][S]) return f[x][S];
	vis[x][S] = 1;
	int y = sum[S] / x;
	for(int st1 = (S - 1) & S; st1; st1 = (st1 - 1) & S)
	{
		int st2 = S ^ st1;
		if(sum[st1] % x == 0 && sum[st2] % x == 0)
			f[x][S] |= solve(std::min(x, sum[st1]/x), st1) 
				&& solve(std::min(x, sum[st2]/x), st2);
		if(sum[st1] % y == 0 && sum[st2] % y == 0)
			f[x][S] |= solve(std::min(y, sum[st1]/y), st1)
				&& solve(std::min(y, sum[st2]/y), st2);
	}
	return f[x][S];
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		int x, y; scanf("%d%d", &x, &y);
		tot = 1 << n;
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		memset(cnt, 0, sizeof(cnt));
		for(int S = 0; S < tot; S++) sum[S] = getSum(S);
		memset(vis, 0, sizeof(vis));
		memset(f, 0, sizeof(f));
		if(x * y == sum[tot-1] && solve(std::min(x, y), (1 << n) - 1))
				printf("Case %d: Yes\n", ++cas);
		else printf("Case %d: No\n", ++cas);
	}
	return 0;
}
