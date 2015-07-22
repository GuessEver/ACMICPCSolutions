#include <cstdio>
#include <algorithm>

const int N = 10000 + 10;

int n;
struct Node{
	int a, idx;
	bool operator < (const Node &b) const
	{
		return a < b.a;
	}
}a[N];
long long dp[N];
int pre[N], g[N];

void printAns(int i)
{
	if(pre[i] == -1) return;
	printAns(pre[i]);
	printf("%d", i - pre[i]);
	for(int k = pre[i] + 1; k <= i; k++) printf(" %d", a[k].idx);
	puts("");
}

int main()
{
	freopen("iq.in", "r", stdin);
	freopen("iq.out", "w", stdout);
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].a);
			a[i].idx = i;
			dp[i] = 0x3f3f3f3f3f3f3f3fll;
			pre[i] = -1; g[i] = 0;
		}
		dp[0] = 0; pre[0] = -1; g[0] = 0;
		std::sort(a+1, a+1+n);
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < i; j++)
			{
				long long tmp = dp[j] + 1ll * a[i].a * (n - j);
				if(tmp < dp[i])
				{
					dp[i] = tmp;
					pre[i] = j; g[i] = g[j] + 1;
				}
			}
		printf("%I64d\n", dp[n]);
		printf("%d\n", g[n]);
		printAns(n);
	}
	return 0;
}
