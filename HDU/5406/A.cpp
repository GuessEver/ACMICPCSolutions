#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define lowbit(_X) ((_X)&(-(_X)))
using std::map;
const int N = 1000 + 10;

struct Node{
	int x, y;
	bool operator < (const Node &b) const
	{
		if(x == b.x) return y < b.y;
		return x > b.x;
	}
}tmp[N];
map<int, int> hash;
int n, a[N], b[N], maxp;
struct BIT{
	int c[N];
	int query(int i)
	{
		int res = 0;
		for(; i > 0; i -= lowbit(i)) res = std::max(res, c[i]);
		return res;
	}
	void update(int i, int x)
	{
		for(; i <= maxp; i += lowbit(i)) c[i] = std::max(c[i], x);
	}
}dp[N];
int f[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d%d", &tmp[i].x, &tmp[i].y);
		std::sort(tmp+1, tmp+1+n);
		for(int i = 1; i <= n; i++) a[i] = b[i] = tmp[i].y;
		std::sort(b+1, b+1+n);
		hash.clear(); maxp = 0;
		for(int i = 1; i <= n; i++)
			if(hash.find(b[i]) == hash.end())
				hash[b[i]] = ++maxp;
		for(int i = 1; i <= n; i++) a[i] = hash[a[i]];
		memset(dp, 0, sizeof(dp));
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= maxp; j++) f[j] = dp[j].query(a[i]) + 1;
			for(int j = 1; j <= maxp; j++)
			{
				dp[j].update(a[i], f[j]);
				dp[a[i]].update(j, f[j]);
			}
		}
		int res = 0;
		for(int i = 1; i <= maxp; i++) res = std::max(res, dp[i].query(maxp));
		printf("%d\n", res);
	}
	return 0;
}
