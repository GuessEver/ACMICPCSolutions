#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int N = 2 * 100000 + 10;
int n, k, A, m, a[N];

int _rmq[N][30];
void init_RMQ(int *_orig)
{
	for(int i = 1; i <= n; i++) _rmq[i][0] = _orig[i];
	for(int j = 1; j <= log(1.0 * n) / log(2.0); j++)
		for(int i = 1; i <= n + 1 - (1 << j); i++)
			_rmq[i][j] = std::min(_rmq[i][j-1], _rmq[i+(1<<(j-1))][j-1]);
}
int query_RMQ(int l, int r)
{
	int k = log(r - l + 1.0) / log(2.0);
	return std::min(_rmq[l][k], _rmq[r-(1<<k)+1][k]);
}

bool check(int mid)
{
	int cnt = 0;
	for(int i = 1; i + A - 1 <= n; i++)
	{
		int tmp = query_RMQ(i, i + A - 1);
		if(tmp >= mid)
		{
			cnt++;
			i += A;
		}
	}
	return cnt >= k;
}

int main()
{
	scanf("%d%d%d", &n, &k, &A);
	scanf("%d", &m);
	for(int i = 1; i <= n; i++) a[i] = m + 1;
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		if(a[x] == m + 1) a[x] = i;
		else { puts("fuck"); while(1); }
	}
	init_RMQ(a);
	int low = 1, high = m + 1, ans = 1;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(check(mid))
		{
			low = mid + 1;
			ans = mid;
		}
		else high = mid - 1;
	}
	if(ans == m + 1) ans = -1;
	printf("%d\n", ans);
	return 0;
}
