#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using std::queue;
using std::pair;
using std::make_pair;

const int N = 100 + 10;
const int M = 1000 + 10;

int cap[N][N], n, m, C;
int dis[N][M];
bool vis[N][M];
typedef pair<int, int> pir;
queue<pir> Q;

int solve()
{
	while(!Q.empty()) Q.pop();
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	vis[1][0] = 1; dis[1][0] = 0;
	Q.push(make_pair(1, 0));
	while(!Q.empty())
	{
		pir tmp = Q.front(); Q.pop();
		int i = tmp.first, k = tmp.second;
		vis[i][k] = 0;
		for(int j = 1; j <= n; j++) if(cap[i][j] != 0x3f3f3f3f)
		{
			if(dis[i][k] + cap[i][j] < dis[j][k])
			{
				dis[j][k] = dis[i][k] + cap[i][j];
				if(!vis[j][k])
				{
					Q.push(make_pair(j, k));
					vis[j][k] = 1;
				}
			}
			if(k < m && dis[i][k] + 0 < dis[j][k+1])
			{
				dis[j][k+1] = dis[i][k] + 0;
				if(!vis[j][k+1])
				{
					Q.push(make_pair(j, k+1));
					vis[j][k+1] = 1;
				}
			}
		}
	//	printf("%d : \n", i);
	//	for(int j = 1; j <= n; j++)
	//		printf("%d ", dis[j][0]); puts("");
	}
	for(int i = 0; i <= m; i++)
		if(dis[n][i] <= C) return i;
}

int main()
{
	while(scanf("%d%d%d", &n, &m, &C) == 3 && (n||m||C))
	{
		memset(cap, 0x3f, sizeof(cap));
		for(int i = 1; i <= m; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if(cap[x][y] > z) cap[x][y] = z;
		}
		printf("%d\n", solve());
	}
	return 0;
}
