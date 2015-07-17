#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using std::multiset;

const int N = 2 * 100000 + 10;

int n, m;
long long l[N], r[N], len[N];
struct SEG{
	long long l, r; int idx;
	bool operator < (const SEG &b) const
	{
		return r < b.r;
	}
}seg[N];
struct BRIDGE{
	long long len; int idx;
	bool operator < (const BRIDGE &b) const
	{
		return len < b.len;
	}
}bridge[N];
multiset<BRIDGE> ll;
int ans[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%I64d%I64d", &l[i], &r[i]);
	for(int i = 1; i < n; i++)
	{
		seg[i].l = l[i+1] - r[i];
		seg[i].r = r[i+1] - l[i];
		seg[i].idx = i;
	}
	std::sort(seg+1, seg+n);
	//for(int i = 1; i < n; i++) printf("%d %d [%d]\n", seg[i].l, seg[i].r, seg[i].idx);
	for(int i = 1; i <= m; i++)
	{
		scanf("%I64d", &bridge[i].len);
		bridge[i].idx = i;
		ll.insert(bridge[i]);
	}
	for(int i = 1; i < n; i++)
	{
		multiset<BRIDGE>::iterator it = ll.lower_bound((BRIDGE){seg[i].l});
		if(it == ll.end() || it -> len > seg[i].r)
		{
			puts("No");
			return 0;
		}
		ans[seg[i].idx] = it -> idx;
		ll.erase(it);
	}
	puts("Yes");
	for(int i = 1; i < n; i++) printf("%d ", ans[i]);
	return 0;
}
