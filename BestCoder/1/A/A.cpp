#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

const int N = 30000 + 10;

int n, m, deg[N];
vector<int> cap[N];
priority_queue<int> Q;
int ans[N], len = 0;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) cap[i].clear();
		for(int i = 1; i <= n; i++) deg[i] = 0;
		len = 0;
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[y].push_back(x);
			deg[x]++;
		}
		for(int i = 1; i <= n; i++) if(!deg[i]) Q.push(i);
		while(!Q.empty())
		{
			int x = Q.top(); Q.pop();
			ans[++len] = x;
			for(vector<int>::iterator it = cap[x].begin(); it < cap[x].end(); it++)
			{
				deg[*it]--;
				if(!deg[*it]) Q.push(*it);
			}
		}
		for(int i = len; i > 1; i--) printf("%d ", ans[i]);
		printf("%d\n", ans[1]);
	}
	return 0;
}
