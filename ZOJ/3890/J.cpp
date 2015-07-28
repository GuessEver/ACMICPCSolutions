#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int N = 20 + 10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n;
struct Node{
	int x, y, step, dir;
	bool gold;
}S;
int cap[N][N];
bool vis[N][N][4][2];
queue<Node> Q;

bool expand(Node now, Node &newnd, int k)
{
	newnd = now; newnd.step++;
	if(k == 0) // go forward
	{
		newnd.x += dx[newnd.dir];
		newnd.y += dy[newnd.dir];
		if(newnd.x < 0 || newnd.x >= n) return 0;
		if(newnd.y < 0 || newnd.y >= n) return 0;
		if(cap[newnd.x][newnd.y] == 1 || cap[newnd.x][newnd.y] == 2) return 0;
		return 1;
	}
	else if(k == 1) // turn left
	{
		newnd.dir = (newnd.dir - 1 + 4) % 4;
		return 1;
	}
	else if(k == 2) // turn right
	{
		newnd.dir = (newnd.dir + 1) % 4;
		return 1;
	}
	else if(k == 3) // grab the gold
	{
		if(cap[newnd.x][newnd.y] == 3)
		{
			newnd.gold = 1;
			return 1;
		}
		else return 0;
	}
}

int BFS()
{
	memset(vis, 0, sizeof(vis));
	while(!Q.empty()) Q.pop();
	S = (Node){0, 0, 0, 0, 0};
	Q.push(S); vis[0][0][0][0] = 1;
	if(cap[0][0] == 1 || cap[0][0] == 2) return -1;
	while(!Q.empty())
	{
		Node now = Q.front(), newnd; Q.pop();
		//printf("%d %d %d %d\n", now.x, now.y, now.dir, now.step);
		for(int k = 0; k < 4; k++)
		{
			if(!expand(now, newnd, k)) continue;
			if(newnd.x == 0 && newnd.y == 0 && newnd.gold)
			{
				int score = 1000 - 10 * (newnd.step + 1);
				return score;
			}
			if(!vis[newnd.x][newnd.y][newnd.dir][newnd.gold])
			{
				vis[newnd.x][newnd.y][newnd.dir][newnd.gold] = 1;
				Q.push(newnd);
			}
		}
	}
	return -1;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int op, x, y;
		memset(cap, 0, sizeof(cap));
		while(scanf("%d%d%d", &op, &x, &y) == 3)
		{
			if(op == -1 && x == -1 && y == -1) break;
			cap[x][y] = op;
		}
		printf("%d\n", BFS());
	}
	return 0;
}
