#include <cstdio>
#include <cstring>
const int N = 100 + 10;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int n, m;
bool cap[N*N];
struct Link{int y; Link *next;}*head[N*N];
int ttt, pre[N*N], vis[N*N];

inline int P(int x, int y)
{
	return (x-1) * n + y;
}

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void read()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		cap[P(x, y)] = 1;
	}
}

void buildmap()
{
	bool flag = 0;
	for(int i = 1; i <= n; i++)
	{
		flag = !flag;
		for(int j = 1; j <= n; j++)
			if((j & 1 && flag) || (j % 2 == 0 && !flag))
				for(int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if(x < 1 || x > n || y < 1 || y > n) continue;
					inLink(P(i, j), P(x, y));
				}
	}
}

bool search(int x)
{
	for(Link *p = head[x]; p; p = p->next)
		if(!cap[p->y] && vis[p->y]!=ttt)
		{
			vis[p->y] = ttt;
			if(pre[p->y] == -1 || search(pre[p->y]))
			{
				pre[p->y] = x;
				return 1;
			}
		}
	return 0;
}

void solve()
{
	buildmap();
	memset(pre, -1, sizeof(pre));
	int res = 0;
	for(int i = 1; i <= n*n; i++)
	{
		if(cap[i]) continue;
		ttt++;
		res += search(i);
	}
	printf("%d\n", res);
}

int main()
{
	read();
	solve();
	return 0;
}
