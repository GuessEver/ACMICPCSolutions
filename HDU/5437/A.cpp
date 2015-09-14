#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::priority_queue;
const int N = 150000 + 10;
int n, m, q;
char name[N][210];
struct People{
	int value, idx;
	bool operator < (const People &y) const
	{
		if(value == y.value) return idx > y.idx;
		return value < y.value;
	}
}a[N];
struct Door{
	int t, p;
	bool operator < (const Door &y) const
	{
		return t < y.t;
	}
}door[N];
int ans[N];
priority_queue<People> Q;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", name[i]);
			scanf("%d", &a[i].value);
			a[i].idx = i;
		}
		//for(int i = 1; i <= n; i++) Q.push(a[i]);
		//while(!Q.empty()) { printf("%d ", Q.top().idx); Q.pop(); }
		for(int i = 1; i <= m; i++) scanf("%d%d", &door[i].t, &door[i].p);
		std::sort(door+1, door+1+m);
		if(door[m].t != n) { door[++m].t = n; door[m].p = n; }
		while(!Q.empty()) Q.pop();
		for(int dooridx = 1, peopleidx = 1, in = 0; dooridx <= m; dooridx++)
		{
			while(peopleidx <= door[dooridx].t) Q.push(a[peopleidx++]);
			for(int j = 1; j <= door[dooridx].p && !Q.empty(); j++)
			{
				ans[++in] = Q.top().idx;
				Q.pop();
			}
		}
		for(int i = 1; i <= q; i++)
		{
			int x; scanf("%d", &x);
			printf("%s%s", name[ans[x]], i == q ? "\n" : " ");
		}
	}
	return 0;
}
