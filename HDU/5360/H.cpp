#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using std::vector;
using std::priority_queue;
using std::pair;

const int N = 100000 + 10;
int n;
struct Node{
	int l, r, idx;
	bool operator < (const Node &b) const
	{
		if(l == b.l) return r < b.r;
		return l < b.l;
	}
}a[N];
priority_queue<pair<int, int> > Q;
vector<int> ans;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		while(!Q.empty()) Q.pop(); ans.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].l);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].r);
		for(int i = 1; i <= n; i++) a[i].idx = i;
		std::sort(a+1, a+1+n);
		int res = 0, i = 0;
		for(i = 1; i <= n;i++)
			if(a[i].l == 0) Q.push(std::make_pair(-a[i].r, a[i].idx));
			else break;
		while(!Q.empty())
		{
			pair<int, int> now = Q.top(); Q.pop();
			ans.push_back(now.second);
			if(-now.first >= res) res++;
			while(i <= n && a[i].l <= res)
			{
				Q.push(std::make_pair(-a[i].r, a[i].idx));
				i++;
			}
		}
		for(; i <= n; i++) ans.push_back(a[i].idx);
		printf("%d\n", res);
		for(int i = 0; i < n; i++)
			printf("%d%s", ans[i], i == n - 1 ? "\n" : " ");
	}
	return 0;
}
