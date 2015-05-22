#include <cstdio>
#include <queue>
#include <set>
using std::set;
using std::queue;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Node{
	int status, pos, steps;
}S;
queue<Node> Q;
int n;
set<int> inQ[25];

bool move(Node &now, Node &newnd, int k)
{
	newnd = now; newnd.steps++;
	int x = newnd.pos / n, y = newnd.pos % n;
	x += dx[k]; y += dy[k];
	if(x < 0 || x >= n || y < 0 || y >= n) return 0;
	newnd.pos = x * n + y;
	if((1 << (n * n - 1 - newnd.pos)) & newnd.status) return 0;
	return 1;
}

void print_status(int status, int pos)
{
	int a[5][5], cx = pos / n, cy = pos % n;
	for(int i = n - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
		{
			a[i][j] = (status & 1);
			status >>= 1;
		}
	a[cx][cy] = 2;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) printf("%d", a[i][j]);
		puts("");
	}
	puts("--------------"); 
}

void expand(Node &now)
{
	int a[5][5], b[5][5] = {0}, status = now.status;
	for(int i = n - 1; i >= 0; i--)
		for(int j = n - 1; j >= 0; j--)
		{
			a[i][j] = (status & 1);
			status >>= 1;
		}
	//print_status(now.status, now.pos);
	int cx = now.pos / n, cy = now.pos % n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			int cnt = 0;
			for(int k = 0; k < 8; k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if(x < 0 || x >= n || y < 0 || y >= n) continue;
				if(a[x][y] == 1 || (x == cx && y == cy)) cnt++;
			}
			if(i == cx && j == cy) b[i][j] = 0;
			else if(a[i][j] == 1)
			{
				if(cnt == 2 || cnt == 3) b[i][j] = 1;
				else b[i][j] = 0;
			}
			else{
				if(cnt == 3) b[i][j] = 1;
				else b[i][j] = 0;
			}
		}
	now.status = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			now.status = now.status * 2 + b[i][j];
	//print_status(now.status, now.pos);
}

int BFS()
{
	if(S.status == 0) return 0;
	while(!Q.empty()) Q.pop();
	for(int i = 0; i < n * n; i++) inQ[i].clear();
	inQ[S.pos].insert(S.status); S.steps = 0; Q.push(S);
	while(!Q.empty())
	{
		Node newnd, now = Q.front(); Q.pop();
		//puts("---end\n\n>>>>");
		//print_status(now.status, now.pos);
		//puts("---start");
		for(int k = 0; k < 8; k++)
		{
			if(!move(now, newnd, k)) continue;
			//printf("k = %d\n", k);
			expand(newnd);
			//print_status(newnd.status, newnd.pos);
			if(newnd.status == 0) return newnd.steps;
			if(inQ[newnd.pos].find(newnd.status) == inQ[newnd.pos].end())
			{
				inQ[newnd.pos].insert(newnd.status);
				Q.push(newnd);
			}
		}
	}
	return -1;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		char tmp; S.status = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				scanf(" %c", &tmp);
				if(tmp == '#') S.status = S.status * 2 + 1;
				else S.status = S.status * 2;
				if(tmp == '@') { S.pos = i * n + j; }
			}
		printf("%d\n", BFS());
	}
	return 0;
}
