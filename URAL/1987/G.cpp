#include <cstdio>
#include <algorithm>
#include <queue>
using std::priority_queue;

const int N = 100000 + 10;

int n, m;
struct Segment{
	int l, r, idx;
	bool operator < (const Segment &b) const
	{
		return r > b.r;
	}
}seg[N];
struct Query{
	int p, idx, ans;
}q[N];
priority_queue<Segment> Q;

bool cmp_r(Segment a, Segment b)
{
	if(a.l == b.l) return a.r < b.r;
	return a.l < b.l;
}
bool cmp_p(Query a, Query b) { return a.p < b.p; }
bool cmp_i(Query a, Query b) { return a.idx < b.idx; }

void Solve()
{
	std::sort(q+1, q+1+m, cmp_p);
	for(int i = 1, j = 1; i <= m; i++)
	{
		while(j <= n && q[i].p >= seg[j].l) 
		{
			Q.push(seg[j]);
			j++;
		}
		while(!Q.empty() && q[i].p > Q.top().r) Q.pop();
		if(!Q.empty()) q[i].ans = Q.top().idx;
		else q[i].ans = -1;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &seg[i].l, &seg[i].r);
		seg[i].idx = i;
	}
	std::sort(seg+1, seg+1+n, cmp_r);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &q[i].p);
		q[i].idx = i;
	}
	Solve();
	std::sort(q+1, q+1+m, cmp_i);
	for(int i = 1; i <= m; i++) printf("%d\n", q[i].ans);
	return 0;
}
