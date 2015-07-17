#include <cstdio>

const int N = 1000 + 10;

int n, m;
int a[N];
long long ans1[100010], ans2[100010];

void solve()
{
	int k = 1;
	for(int i = 1; i <= 100000; i++)
	{
		ans2[i] = ans2[i-1];
		ans1[i] = ans1[i-1];
		if(k == n + 1) continue;
		ans2[i] += m;
		while(k <= n && ans2[i] >= a[k])
		{
			ans2[i] -= a[k];
			ans1[i]++;
			k++;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	solve();
	int q; scanf("%d", &q);
	while(q--)
	{
		int d; scanf("%d", &d);
		printf("%I64d %I64d\n", ans1[d], ans2[d]);
	}
	return 0;
}
