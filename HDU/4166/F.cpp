#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int dx[] = {0, 1,  0, -1};
const int dy[] = {1, 0, -1,  0}; // E S W N

int n, m, mod;
struct Node{
	int x, y, dir, step;
	bool operator == (const Node &b)
		{ return x == b.x && y == b.y; }
}S, T;
char cap[1010][1010];
queue<Node> Q;
bool vis[1010][1010][5];
int dis[1010][1010][5], num[1010][1010][5];
int minDis;

bool expand(Node &now, Node &newnd, int k)
{
	newnd = now;
	newnd.step++;
	if(k == 0)
	{
		int nx = now.x + dx[now.dir];
		int ny = now.y + dy[now.dir];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) return 0;
		if(cap[nx][ny] == '*') return 0;
		newnd.x = nx; newnd.y = ny;
		return 1;
	}
	else{
		newnd.dir = (newnd.dir + k + 4) % 4;;
		return 1;
	}
}

void BFS()
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0, sizeof(dis));
	memset(num, 0, sizeof(num));
	while(!Q.empty()) Q.pop();
	Q.push(S);
	num[S.x][S.y][S.dir] = 1;
	vis[S.x][S.y][S.dir] = 1;
	dis[S.x][S.y][S.dir] = 0;
	minDis = -1;
	if(S == T)
	{
		minDis = 0;
		return;
	}
	while(!Q.empty())
	{
		Node now = Q.front(); Q.pop();
		//printf("%d %d %d\n", now.x, now.y, now.dir);
		Node newnd;
		for(int k = -1; k <= 1; k++)
		{
			if(expand(now, newnd, k))
			{
				if(newnd == T)
				{
					if(minDis == -1) minDis = newnd.step;
					if(newnd.step > minDis) return;
				}
				int &D = dis[newnd.x][newnd.y][newnd.dir];
				if(!vis[newnd.x][newnd.y][newnd.dir])
				{
					vis[newnd.x][newnd.y][newnd.dir] = 1;
					Q.push(newnd);
					D = newnd.step;
				}
				if(newnd.step == D)
				{
					num[newnd.x][newnd.y][newnd.dir] += num[now.x][now.y][now.dir];
					num[newnd.x][newnd.y][newnd.dir] %= mod;
				}
			}
		}
	}
}

int main()
{
	int cas = 0;
	while(scanf("%d%d%d", &n, &m, &mod) == 3 && mod)
	{
		for(int i = 0; i < n; i++) scanf("%s", cap[i]);
		int x, y; scanf("%d%d", &x, &y);
		S.x = x; S.y = y; S.step = 0;
		scanf("%d%d", &x, &y);
		T.x = x; T.y = y;
		char dir; scanf(" %c", &dir);
		if(dir == 'E') S.dir = 0;
		else if(dir == 'S') S.dir = 1;
		else if(dir == 'W') S.dir = 2;
		else S.dir = 3;
		BFS();
		int res = 0;
		for(int i = 0; i < 4; i++)
			if(dis[T.x][T.y][i] == minDis)
				res = (res + num[T.x][T.y][i]) % mod;
		if(minDis == -1) res = -1;
		printf("Case %d: %d %d\n", ++cas, mod, res);
	}
	return 0;
}
