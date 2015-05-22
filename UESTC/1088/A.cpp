#include <cstdio>
#include <cstring>
#include <queue>
using std::queue;

const int N = 30 + 10;
const int dx[] = {0, 0, 1, -1, 0, 0};
const int dy[] = {1, -1, 0, 0, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

int L, n, m;
struct Node{
	int x, y, z, steps;
	Node() {}
	Node(int a, int b, int c)
	{
		x = a; y = b; z = c;
		steps = 0;
	}
	bool operator == (const Node &b) const
	{
		return x == b.x && y == b.y && z == b.z;
	}
}S, T;
queue<Node> Q;
char cap[N][N][N];
bool inQ[N][N][N];

bool expand(Node &now, Node &newnd, int k)
{
	newnd = now; newnd.steps++;
	newnd.x += dx[k]; newnd.y += dy[k]; newnd.z += dz[k];
	if(newnd.x < 1 || newnd.x > n) return 0;
	if(newnd.y < 1 || newnd.y > m) return 0;
	if(newnd.z < 1 || newnd.z > L) return 0;
	if(cap[newnd.x][newnd.y][newnd.z] == '#') return 0;
	return 1;
}

int BFS()
{
	if(S.x == -1 || T.x == -1) return -1;
	while(!Q.empty()) Q.pop();
	memset(inQ, 0, sizeof(inQ));
	Q.push(S); inQ[S.x][S.y][S.z] = 1;
	while(!Q.empty())
	{
		Node newnd, now = Q.front(); Q.pop();
		//printf("(%d, %d, %d) %d\n", now.x, now.y, now.z, now.steps);
		for(int k = 0; k < 6; k++)
		{
			if(!expand(now, newnd, k)) continue;
			if(!inQ[newnd.x][newnd.y][newnd.z])
			{
				inQ[newnd.x][newnd.y][newnd.z] = 1;
				if(newnd == T) return newnd.steps;
				Q.push(newnd);
			}
		}
	}
	return -1;
}

int main()
{
	while(scanf("%d%d%d", &L, &n, &m) == 3 && (L || n || m))
	{
		S = T = Node(-1, -1, -1);
		for(int i = 1; i <= L; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= m; k++)
				{
					scanf(" %c", &cap[j][k][i]);
					if(cap[j][k][i] == 'S') S = Node(j, k, i);
					if(cap[j][k][i] == 'E') T = Node(j, k, i);
				}
		int res = BFS();
		if(res == -1) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n", res);
	}
	return 0;
}
