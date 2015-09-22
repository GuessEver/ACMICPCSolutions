#include <cstdio>
const int N = 100000 + 10;
int n, a[N], dp[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int res = 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= a[i-1]) dp[i] = dp[i-1] + 1;
		else dp[i] = 1;
		if(dp[i] > res) res = dp[i];
		//printf("%d ", dp[i]);
	}
	printf("%d\n", res);
	return 0;
}
