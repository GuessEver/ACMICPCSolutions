#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 1000 + 10;

int n, m;
bool vis[N];
vector<int> old[N], cap[N];
int f[N][2];
int g[N][2];

void dfs(int x, int pre)
{
	if(vis[x]) return;
	vis[x] = 1;
	cap[pre].push_back(x);
	for(vector<int>::iterator it = old[x].begin(); it < old[x].end(); it++)
		dfs(*it, x);
}

int solve(int x, bool color) // Now at point `x`, its status is `color`
{
	if(f[x][color] != -1) return f[x][color];
	f[x][color] = g[x][color] = 0;
	for(vector<int>::iterator it = cap[x].begin(); it < cap[x].end(); it++)
	{
		if(color)
		{
			solve(*it, 0); solve(*it, 1);
			if(f[*it][0] < f[*it][1])
			{
				f[x][color] += f[*it][0];
				g[x][color] += g[*it][0];
			}
			else if(f[*it][0] > f[*it][1])
			{
				f[x][color] += f[*it][1];
				g[x][color] += g[*it][1] + (x > 0);
			}
			else{
				f[x][color] += f[*it][0];
				g[x][color] += std::max(g[*it][0], g[*it][1] + (x > 0));
			}
		}
		else {
			f[x][color] += solve(*it, 1);
			g[x][color] += g[*it][1];
		}
	}
	if(color) f[x][color]++;
	return f[x][color];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i <= n; i++) cap[i].clear();
		for(int i = 0; i <= n; i++) old[i].clear();
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			x++; y++;
			old[x].push_back(y);
			old[y].push_back(x);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, 0);
		memset(f, -1, sizeof(f));
		memset(g, 0, sizeof(g));
		solve(0, 1);
		printf("%d %d %d\n", f[0][1] - 1, g[0][1], m - g[0][1]);
		//for(int i = 1; i <= n; i++) printf("f[%d][0] = %d, f[%d][1] = %d\n", i, f[i][0], i, f[i][1]);
	}
	return 0;
}
