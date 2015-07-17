#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using std::queue;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char cap[510][510];
struct Node{
	int x, y;
}S, T;
queue<Node> Q;
bool vis[510][510];

bool expand(Node &now, Node &newnd, int k)
{
	newnd = now;
	newnd.x += dx[k]; newnd.y += dy[k];
	if(newnd.x < 1 || newnd.x > n) return 0;
	if(newnd.y < 1 || newnd.y > m) return 0;
	return 1;
}

bool BFS()
{
	Q.push(S); vis[S.x][S.y] = 1;
	while(!Q.empty())
	{
		Node newnd, now = Q.front(); Q.pop();
		//printf("(%d, %d)\n", now.x, now.y);
		for(int k = 0; k < 4; k++)
		{
			if(!expand(now, newnd, k)) continue;
			if(newnd.x == T.x && newnd.y == T.y) return 1;
			if(!vis[newnd.x][newnd.y] && cap[newnd.x][newnd.y] == '.')
			{
				vis[newnd.x][newnd.y] = 1;
				Q.push(newnd);
			}
		}
	}
	return 0;
}

int Count(Node p)
{
	int res = 0;
	for(int k = 0; k < 4; k++)
	{
		int nx = p.x + dx[k];
		int ny = p.y + dy[k];
		if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
		res += cap[nx][ny] == '.';
	}
	return res;
}

bool Solve()
{
	if(S.x == T.x && S.y == T.y)
	{
		int res = Count(T);
		if(res) return 1; else return 0;
	}
	if((abs(S.x - T.x) == 1 && S.y == T.y) || (S.x == T.x && abs(S.y - T.y) == 1))
	{
		if(cap[T.x][T.y] == 'X') return 1;
		int res = Count(T);
		if(res) return 1; else return 0;
	}
	if(!BFS()) return 0;
	if(cap[T.x][T.y] == 'X') return 1;
	int res = Count(T);
	if(res >= 2) return 1; else return 0;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf(" %c", &cap[i][j]);
	scanf("%d%d", &S.x, &S.y);
	scanf("%d%d", &T.x, &T.y);
	if(Solve()) puts("YES"); else puts("NO");
	return 0;
}
