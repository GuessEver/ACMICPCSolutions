#include <cstdio>
const int N = 100000 + 10;

int n, a[N];
bool add[N], ans[N], flag = 0;

void dfs(int x)
{
	if(flag) return;
	if(x > n)
	{
		long long sum = 0;
		for(int i = 1; i <= n; i++)
		{
			if(add[i]) sum += a[i];
			else sum -= a[i];
		}
		if(sum == 0)
		{
			flag = 1;
			for(int i = 1; i <= n; i++) ans[i] = add[i];
		}
		return;
	}
	add[x] = 0; dfs(x + 1);
	add[x] = 1; dfs(x + 1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1);
	if(!flag) puts("No");
	else {
		puts("Yes");
		for(int i = 1; i <= n; i++)
			printf("%d%s", ans[i] ? 1 : -1, i == n ? "\n" : " ");
	}
	return 0;
}
