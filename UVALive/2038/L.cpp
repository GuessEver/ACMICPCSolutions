#include <cstdio>
#include <vector>
#include <cstring>
using std::vector;

const int N = 1500 + 10;

int n;
vector<int> old[N], cap[N];
bool vis[N];
int f[N][2];

void dfs(int x)
{
	for(vector<int>::iterator it = old[x].begin(); it < old[x].end(); it++)
		if(!vis[*it])
		{
			vis[*it] = 1;
			cap[x].push_back(*it);
			dfs(*it);
		}
}

int solve(int x, int status)
{
	if(f[x][status] != -1) return f[x][status];
	f[x][status] = 0;
	for(vector<int>::iterator it = cap[x].begin(); it < cap[x].end(); it++)
	{
		if(status)
			f[x][status] += std::min(solve(*it, 0), solve(*it, 1));
		else
			f[x][status] += solve(*it, 1);
	}
	f[x][status] += status;
	return f[x][status];
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 0; i <= n; i++) cap[i].clear();
		for(int i = 0; i <= n; i++) old[i].clear();
		for(int i = 1; i <= n; i++)
		{
			int x, tmp; scanf("%d:(%d)", &x, &tmp); x++;
			while(tmp--)
			{
				int y; scanf("%d", &y); y++;
				old[x].push_back(y);
				old[y].push_back(x);
			}
		}
		memset(vis, 0, sizeof(vis));
		vis[1] = 1; dfs(1);
		cap[0].push_back(1);
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(0, 1) - 1);
	}
	return 0;
}
