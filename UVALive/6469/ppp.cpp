#include <cstdio>
#include <cstring>

int n, k;
long long res;
int h[100];
int a[100];

bool check()
{
	bool flag = 1;
	for(int i = 1; i <= k; i++)
		if(a[i] == i) flag = 0;
	return flag;
}

void dfs(int x)
{
	if(x > n)
	{
		if(check()) res++;
		return;
	}
	for(int i = 1; i <= n; i++) if(!h[i])
	{
		h[i] = 1;
		a[x] = i;
		dfs(x+1);
		h[i] = 0;
	}
}

void solve()
{
	scanf("%d%d", &n, &k);
	memset(h, 0, sizeof(h));
	res = 0;
	dfs(1);
	printf("%I64d\n", res);
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("ppp.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		solve();
	}
	return 0;
}
