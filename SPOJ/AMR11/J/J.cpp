#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using std::queue;

const int N = 500 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m;
char cap[N][N];
int CC[N][N];
struct Node{int x, y, cnt;};
queue<Node> Q;

void printmap()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			printf("%c", cap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void expand(Node tmp, int k)
{
	if(cap[tmp.x][tmp.y] == '*') return;
	Node p = tmp;
	p.x += dx[k];
	p.y += dy[k];
	p.cnt++;
	if(p.x < 1 || p.x > n) return;
	if(p.y < 1 || p.y > m) return;
	if(cap[p.x][p.y] == '#' || cap[p.x][p.y] == '*') return;
	if(cap[p.x][p.y] == '.')
	{
		cap[p.x][p.y] = cap[tmp.x][tmp.y];
		CC[p.x][p.y] = p.cnt;
		Q.push(p);
		return;
	}
	if(isalpha(cap[p.x][p.y]) && cap[tmp.x][tmp.y] != cap[p.x][p.y] 
			&& CC[p.x][p.y] == p.cnt)
	{
		cap[p.x][p.y] = '*';
		return;
	}
}

void solve()
{
	memset(CC, 0, sizeof(CC));
	while(!Q.empty())
	{
		int times = Q.size();
		while(times--)
		{
			Node now = Q.front();
			Q.pop();
			for(int k = 0; k < 4; k++)
				expand(now, k);
		}
		//printmap();
	}
	printmap();
}

int main()
{
	freopen("J.in", "r", stdin);
	//freopen("J.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", cap[i]+1);
			for(int j = 1; j <= m; j++)
				if(isalpha(cap[i][j]))
				{
					Node tmp = (Node){i, j, 0};
					Q.push(tmp);
				}
		}
		solve();
	}
	return 0;
}
