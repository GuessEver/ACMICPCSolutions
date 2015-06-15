#include <cstdio>
#include <cstring>

const int N = 2000 + 10;
const int mod = 1000000009;

int n, m;
struct Link{
	int y, z;
	Link *next;
}*head[N];
int dist[N], g[N];
bool done[N];

void inLink(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = head[x];
	head[x] = p;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0; g[1] = 1;
	for(int i = 1; i <= n; i++)
	{
		int x = -1;
		for(int j = 1; j <= n; j++)
			if(!done[j] && (x == -1 || dist[j] < dist[x])) x = j;
		done[x] = 1;
		for(Link *p = head[x]; p; p = p -> next)
		{
			if(dist[p->y] > dist[x] + p->z)
			{
				dist[p->y] = dist[x] + p->z;
				if(g[x] != -1 && p->z != 0) g[p->y] = g[x] % mod;
				else g[p->y] = -1;
			}
			else if(dist[p->y] == dist[x] + p->z)
			{
				if(g[p->y] != -1 && g[x] != -1 && p->z != 0) g[p->y] = (g[p->y] + g[x]) % mod;
				else g[p->y] = -1;
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		inLink(a, b, c);
		inLink(b, a, c);
	}
	dijkstra();
	//printf("%d\n", dist[n]);
	printf("%d\n", g[n]);
	return 0;
}
