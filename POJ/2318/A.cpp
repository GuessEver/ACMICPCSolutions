#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 5000 + 10;
int n, m;
struct Point{int x, y;}LT, RB;
struct Seg {
	int s, e;
	bool operator < (const Seg &b) const
	{
		return s < b.s;
	}
}seg[N];
int cnt[N];

int calc(int x, int y)
{
	for(int i = 0; i <= n; i++)
	{
		int v1x = seg[i].s - x, v1y = LT.y - y;
		int v2x = seg[i].e - x, v2y = RB.y - y;
		if(1ll * v1x * v2y - 1ll * v1y * v2x < 0) return i;
	}
}

int main()
{
	bool first = 1;
	while(scanf("%d", &n) == 1 && n)
	{
		scanf("%d%d%d%d%d", &m, &LT.x, &LT.y, &RB.x, &RB.y);
		for(int i = 0; i < n; i++) scanf("%d%d", &seg[i].s, &seg[i].e);
		std::sort(seg, seg + n);
		seg[n].s = seg[n].e = RB.x;
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cnt[calc(x, y)]++;
		}
		if(!first) puts(""); else first = 0;
		for(int i = 0; i <= n; i++) printf("%d: %d\n", i, cnt[i]);
	}
	return 0;
}
