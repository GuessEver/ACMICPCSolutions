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

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) cap[i].clear();
		for(int i = 1; i <= n; i++) deg[i] = 0;
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[x].push_back(y);
			deg[y]++;
		}
		for(int i = 1; i <= n; i++) if(!deg[i]) Q.push(-i);
		bool space = 0;
		while(!Q.empty())
		{
			int x = -Q.top(); Q.pop();
			if(space) putchar(' ');
			space = 1;
			printf("%d", x);
			for(vector<int>::iterator it = cap[x].begin(); it < cap[x].end(); it++)
			{
				deg[*it]--;
				if(!deg[*it]) Q.push(-*it);
			}
		}
		puts("");
	}
	return 0;
}
