#include <cstdio>
const int N = 100 + 10;

int n, K, a[N];
int ans[N];

bool check(int mid)
{
	int i = n+1;
	int sum = 0, num = 1;
	while(i > 1)
	{
		i--;
		if(sum + a[i] > mid)
		{
			sum = a[i];
			num++;
		}
		else sum += a[i];
	}
	return num <= K;
}

int main()
{
	freopen("3162.in", "r", stdin);
	freopen("3162.out", "w", stdout);
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int L = 0, R = 0x3f3f3f3f, mid;
	while(L < R)
	{
		mid = (L + R) / 2;
		if(check(mid)) R = mid;
		else L = mid + 1;
	}
	int i = n+1, val = L, sum = 0, num = 0;
	while(i > 1)
	{
		i--;
		if(sum + a[i] > val)
		{
			sum = a[i];
			ans[++num+1] = i;
		}
		else sum += a[i];
	}
	ans[1] = n;
	for(int i = K; i >= 1; i--)
		printf("%d %d\n", ans[i+1]+1, ans[i]);
	return 0;
}
