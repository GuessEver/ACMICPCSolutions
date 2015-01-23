#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using std::queue;
using std::max;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int L, n, m, tot, Time;
int cap[20][110][110];
bool vis[20][110][110];
struct Node{int floor, x, y, step;}start;
int dist[110], w[110];
queue<Node> Q;
int dp[10010];

bool check(Node now, Node &next)
{
	next = now; next.step++;
	if(cap[now.floor][now.x][now.y] == -1) // upstairs
	{
		next.floor++;
		return 1;
	}
	if(cap[now.floor][now.x][now.y] == -2) // downstairs
	{
		next.floor--;
		return 1;
	}
	return 0;
}

bool expand(Node now, Node &next, int k)
{
	next = now; next.step++;
	int nx = now.x + dx[k]; next.x = nx;
	int ny = now.y + dy[k]; next.y = ny;
	if(nx < 1 || nx > n || ny < 1 || ny > m) return 0;
	if(cap[next.floor][nx][ny] == -3) return 0;
	return 1;
}

void BFS()
{
	while(!Q.empty()) Q.pop();
	Q.push(start);
	vis[start.floor][start.x][start.y] = 1;
	int cnt = 0;
	while(cnt < tot && !Q.empty())
	{
		Node now = Q.front(); Q.pop();
		Node next;
		for(int k = 0; k < 4; k++)
		{
			if(!expand(now, next, k)) continue;
			if(!vis[next.floor][next.x][next.y])
			{
				Q.push(next);
				vis[next.floor][next.x][next.y] = 1;
				if(cap[next.floor][next.x][next.y] > 0)
				{
					dist[cap[next.floor][next.x][next.y]] = next.step;
					cnt++;
				}
			}
		}
		if(check(now, next))
			if(!vis[next.floor][next.x][next.y])
			{
				Q.push(next);
				vis[next.floor][next.x][next.y] = 1;
			}
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d%d", &L, &n, &m, &tot, &Time);
		memset(cap, 0, sizeof(cap));
		memset(vis, 0, sizeof(vis));
		memset(dist, 0x3f, sizeof(dist));
		for(int k = 1; k <= L; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++)
				{
					char ch; scanf(" %c", &ch);
					if(ch == 'S') start = (Node){k, i, j, 0};
					if(ch == 'U') cap[k][i][j] = -1; // upstairs
					else if(ch == 'D') cap[k][i][j] = -2; // downstaris
					else if(ch == 'X') cap[k][i][j] = -3; // cannot reach
				}
		for(int i = 1; i <= tot; i++)
		{
			int fl, x, y;
			scanf("%d%d%d%d", &fl, &x, &y, &w[i]);
			cap[fl][x][y] = i;
		}
		BFS();
		//puts("+++++++++++++++");
		//for(int i = 1; i <= tot; i++)
		//	printf("%d : %d\n", i, dist[i]);
		//puts("===============");
		for(int i = 1; i <= tot; i++)
			if(dist[i] != 0x3f3f3f3f) dist[i] *= 3;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= tot; i++)
			for(int j = Time; j >= dist[i]; j--)
			{
				dp[j] = std::max(dp[j], dp[j-dist[i]] + w[i]);
			}
		printf("%d\n", dp[Time]);
	}
	return 0;
}
