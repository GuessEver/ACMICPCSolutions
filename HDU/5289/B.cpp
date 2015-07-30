#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using std::pair;

const int N = 100000 + 10;

int n, k, a[N];
int rmq_min[N][30], rmq_max[N][30];
void rmq_init()
{
	for(int i = 1; i <= n; i++) rmq_min[i][0] = rmq_max[i][0] = a[i];
	for(int j = 1; j <= log(1.0 * n) / log(2.0); j++)
		for(int i = 1; i <= n + 1 - (1 << j); i++)
		{
			rmq_min[i][j] = std::min(rmq_min[i][j-1], rmq_min[i+(1<<(j-1))][j-1]);
			rmq_max[i][j] = std::max(rmq_max[i][j-1], rmq_max[i+(1<<(j-1))][j-1]);
		}
}
pair<int, int> rmq_query(int l, int r)
{
	int k = log(r - l + 1.0) / log(2.0);
	int min = std::min(rmq_min[l][k], rmq_min[r-(1<<k)+1][k]);
	int max = std::max(rmq_max[l][k], rmq_max[r-(1<<k)+1][k]);
	return std::make_pair(min, max);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		rmq_init();
		long long res = 0;
		for(int i = 1; i <= n; i++)
		{
			int low = i, high = n, ans = low;
			while(low <= high)
			{
				int mid = low + (high - low) / 2;
				pair<int, int> tmp = rmq_query(i, mid);
				if(tmp.second - tmp.first >= k) high = mid - 1;
				else { low = mid + 1; ans = mid; }
			}
			//printf("%d %d\n", i, ans);
			res += ans - i + 1;
		}
		printf("%lld\n", res);
	}
	return 0;
}
