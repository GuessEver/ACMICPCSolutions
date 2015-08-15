#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
const int N = 10000 + 10;

int n, m, k;
struct Node{
	int score, status;
	bool operator < (const Node &b) const
	{
		return score > b.score;
	}
}a[N];
vector<Node> v[1050];
struct Query{
	int idx, p;
};
vector<Query> q[1050];
int ans[N*10];
int tot;

int main()
{
	scanf("%d%d", &n, &k);
	tot = (1 << k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].score);
		int x, res = 0; scanf("%d", &x);
		while(x--)
		{
			int y; scanf("%d", &y);
			res |= (1 << (y - 1));
		}
		a[i].status = res;
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int p, x, res = 0;
		scanf("%d", &p);
		scanf("%d", &x);
		while(x--)
		{
			int y; scanf("%d", &y);
			res |= (1 << (y - 1));
		}
		q[res].push_back((Query){i, p});
	}
	for(int i = 0; i < tot; i++) if(!q[i].empty())
	{
		for(int j = 0; j < tot; j++) v[j].clear();
		for(int j = 1; j <= n; j++)
			v[a[j].status & i].push_back(a[j]);
		for(int j = 0; j < tot; j++) std::sort(v[j].begin(), v[j].end());
		for(vector<Query>::iterator it = q[i].begin(); it != q[i].end(); it++)
		{
			int tmp = (a[it -> p].status & i);
			int pos = std::lower_bound(v[tmp].begin(), v[tmp].end(), a[it -> p]) - v[tmp].begin() + 1;
			ans[it -> idx] = pos;
		}
	}
	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
