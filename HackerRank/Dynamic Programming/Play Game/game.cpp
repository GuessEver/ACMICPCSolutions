#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

const int N = 100000 + 10;
int n, a[N];
long long f[N], sum[N];

void solve()
{
	f[1] = a[1]; f[2] = a[1] + a[2]; f[3] = f[2] + a[3];
	for(int i = 4; i <= n; i++)
	{
		f[i] = sum[i-1] - f[i-1] + a[i];
		f[i] = max(f[i], sum[i-2] - f[i-2] + a[i] + a[i-1]);
		f[i] = max(f[i], sum[i-3] - f[i-3] + a[i] + a[i-1] + a[i-2]);
	}
	printf("%lld\n", f[n]);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = n; i >= 1; i--) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
		solve();
	}
	return 0;
}
