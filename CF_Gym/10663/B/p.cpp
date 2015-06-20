#include <cstdio>

int n, k;
int s[310];
int ans = 0;

void dfs(int x, int sum, int max)
{
	if(x > n)
	{
		ans += (sum == 0 && max == k);
		return;
	}
	dfs(x + 1, sum + 1, (sum+1 > max) ? sum+1 : max); // (
	dfs(x + 1, sum, max); // 0
	if(sum > 0) dfs(x + 1, sum - 1, max); // )
}

int main()
{
	scanf("%d%d", &n, &k);
	dfs(1, 0, 0);
	printf("%d\n", ans);
	return 0;
}
