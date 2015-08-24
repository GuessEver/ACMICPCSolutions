#include <cstdio>
#include <algorithm>
const int N = 1000000 + 10;

int n, a[N], dp[N];
int c[N];

inline int lowbit(int x) { return x & -x; }
void update(int i, int x)
{
	for(; i <= n; i += lowbit(i)) c[i] = std::max(c[i], x);
}
int query(int i)
{
	int res = 0;
	for(; i > 0; i -= lowbit(i)) res = std::max(res, c[i]);
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = query(i - 2) + a[i];
		if(i - 2 >= 1) update(i - 2, dp[i - 2]);
		res = std::max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
}
