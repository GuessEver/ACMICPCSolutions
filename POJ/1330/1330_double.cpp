#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 10000 + 10;

const int UPDeepth = 14;
int n;
struct Link{
	int y;
	Link *next;
}*head[N];
bool in[N];
int ancient[N][17];
int deep[N];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x, int deepth, int father)
{
	deep[x] = deepth;
	ancient[x][0] = father;
	for(Link *p = head[x]; p; p = p -> next)
		dfs(p -> y, deepth + 1, x);
}

void getLCA()
{
	for(int i = 1; i <= n; i++)
		if(!in[i]) dfs(i, 1, 0);
	for(int j = 1; j <= UPDeepth; j++)
		for(int i = 1; i <= n; i++)
			ancient[i][j] = ancient[ancient[i][j-1]][j-1];
}

int LCA(int x, int y)
{
	if(deep[x] > deep[y]) std::swap(x, y); // deep[x] <= deep[y]
	for(int j = UPDeepth; j >= 0; j--)
		if(deep[x] <= deep[ancient[y][j]]) y = ancient[y][j];
	if(x == y) return x;
	for(int j = UPDeepth; j >= 0; j--)
		if(ancient[x][j] != ancient[y][j])
		{
			x = ancient[x][j];
			y = ancient[y][j];
		}
	return ancient[y][0];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(head, 0, sizeof(head));
		memset(ancient, 0, sizeof(ancient));
		memset(in, 0, sizeof(in));
		memset(deep, 0, sizeof(deep));
		scanf("%d", &n);
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y); in[y] = 1;
		}
		getLCA();
		int x, y; scanf("%d%d", &x, &y);
		printf("%d\n", LCA(x, y));
	}
	return 0;
}
