#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::max;
#define sqr(_X) ((_X)*(_X))

const int N = 200 + 10;

int n, T;
struct Node{
	int x, y, t, v;
	void Read()
	{
		scanf("%d%d%d%d", &x, &y, &t, &v);
	}
}a[N][N];
struct Link{
	int y; Link *next;
}*head[N*2];
int f[40010];
int len[N];
int fa[N];

int D(Node &aa)
{
	return (aa.x * aa.x + aa.y * aa.y);
}
bool isLine(Node &ai, Node &aj)
{
	int x1 = ai.x, y1 = ai.y;
	int x2 = aj.x, y2 = aj.y;
	return x1 * y2 == x2 * y1;
}

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void build(int root, int x)
{
	if(!head[x]) return;
	for(Link *p = head[x]; p; p = p -> next)
	{
		len[root]++;
		a[root][len[root]].t = a[root][len[root]-1].t + a[p->y][1].t;
		a[root][len[root]].v = a[root][len[root]-1].v + a[p->y][1].v;
		build(root, p -> y);
	}
}

int main()
{
	int cas = 0;
	while(scanf("%d%d", &n, &T) == 2)
	{
		memset(head, 0, sizeof(head));
		memset(f, 0, sizeof(f));
		memset(fa, 0, sizeof(fa));
		memset(len, 0, sizeof(len));
		for(int i = 1; i <= n; i++) a[i][1].Read();
		for(int i = 1; i <= n; i++) if(!head[i])
		{
			int k = -1, ddd = 0;
			for(int j = 1; j <= n; j++) if(i != j)
			{
				int tmp = D(a[j][1]) - D(a[i][1]);
				if(isLine(a[i][1], a[j][1]) && tmp > 0)
				{
					if(k == -1 || ddd > tmp)
					{
						k = j;
						ddd = tmp;
					}
				}
			}
			if(k == -1) continue;
			inLink(i, k);
			fa[k] = i;
		}
		for(int i = 1; i <= n; i++) if(fa[i] == 0)
		{
			len[i] = 1;
			build(i, i);
		}
	//	for(int i = 1; i <= n; i++) if(fa[i] == 0)
	//		for(int j = 1; j <= len[i]; j++)
	//			printf("a[%d][%d] = (t)%d   (v)%d\n", i, j, a[i][j].t, a[i][j].v);
		for(int i = 1; i <= n; i++) if(fa[i] == 0)
			for(int j = T; j >= 0; j--)
			{
				for(int k = 1; k <= len[i]; k++)
				{
					if(j >= a[i][k].t)
						f[j] = max(f[j], f[j-a[i][k].t] + a[i][k].v);
				}
			}
	//	for(int i = 0; i <= T; i++) printf("f[%d] = %d\n", i, f[i]);
		printf("Case %d: %d\n", ++cas, f[T]);
	}
	return 0;
}
