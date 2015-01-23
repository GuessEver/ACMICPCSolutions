#include <cstdio>
#include <utility>
#include <queue>
#include <cstring>
using std::pair;
using std::make_pair;
using std::queue;

const int N = 1000 + 10;
int n, m, a[N], b[N], c[2*N];
typedef pair<int, int> pir;
queue<pir> Q;
bool vis[N][N];

bool BFS()
{
	memset(vis, 0, sizeof(vis));
	while(!Q.empty()) Q.pop();
	Q.push(make_pair(1, 1));
	for(int p = 1; p <= n + m; p++)
	{
		int sz = Q.size();
		for(int t = 1; t <= sz; t++)
		{
			int i = Q.front().first;
			int j = Q.front().second;
			Q.pop();
			if(i <= n && a[i] == c[p])
			{
				if(!vis[i+1][j])
				{
					vis[i+1][j] = 1;
					Q.push(make_pair(i+1, j));
				}
			}
			if(j <= m && b[j] == c[p])
			{
				if(!vis[i][j+1])
				{
					vis[i][j+1] = 1;
					Q.push(make_pair(i, j+1));
				}
			}
		}
	}
	return !Q.empty();
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n+m; i++) scanf("%d", &c[i]);
		if(BFS()) puts("possible");
		else puts("not possible");
	}
	return 0;
}
