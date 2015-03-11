// By UESTC_QuantalIris
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000007
#define MP make_pair
const int NUM = 30010;
const double eps = 1e-10, pi = acos(-1.0);
using namespace std;
typedef pair <int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
int n, m;
int fa[NUM];
vector<int> g[NUM];
char name[NUM][100];
int num[NUM];
map<string, int> mp;
int stk[NUM], top;
int cmp(int x, int y)
{
	return strcmp(name[x], name[y]) < 0;
}

struct oper
{
	int type;
	int x, y;
	int i;
} op[NUM];
struct edge
{
	int to, next, lca;
} e[NUM * 2];
int head[NUM], tot;
int init()
{
	memset(head, -1, sizeof(head));
	top = 0;
	tot = 0;
	mp.clear();
	for(int i = 1; i <= n; i++)
	{
		g[i].clear();
	}
}
void add_edge(int u, int v)
{
	e[tot] = (edge) {v, head[u], 0};
	head[u] = tot++;
}

int pa[NUM];
int find(int x)
{
	if(x != pa[x])
		pa[x] = find(pa[x]);
	return pa[x];
}
bool vis[NUM];

void LCA(int u)
{
	pa[u] = u;
	int k;
	vis[u] = true;
	for(k = 0; k < g[u].size(); k++)
		if(!vis[g[u][k]])
		{
			LCA(g[u][k]);
			pa[g[u][k]] = u;
		}
	for(k = head[u]; k != -1; k = e[k].next)
		if(vis[e[k].to])
		{
			e[k ^ 1].lca = e[k].lca = find(e[k].to);
		}
}

void pr(int u)
{
	sort(g[u].begin(), g[u].end(), cmp);
	for(int i = 0; i < g[u].size(); i++)
		if(g[u][i] != fa[u])
		{
			printf("%s\n", name[g[u][i]]);
			pr(g[u][i]);
		}
}
int main()
{
#ifdef ACM_TEST
	freopen("in.txt", "r", stdin);
//	freopen("in.txt", "w", stdout);
#endif
	int i, j;
	char s[300];
	while(~scanf("%d", &n) && n)
	{
		init();
		fa[1] = 1;
		for(i = 1; i <= n; i++)
		{
			scanf("%s", name[i]);
			j = 0;
			while(name[i][j] == '.')j++;
			mp[name[i] + j] = i;
			num[i] = j;
			while(top > j)top--;
			if(j)
			{
				fa[i] = stk[top - 1];
				g[fa[i]].push_back(i);
				g[i].push_back(fa[i]);
			}
			stk[top++] = i;
		}
		scanf("%d", &m);
		for(i = 0; i < m; i++)
		{
			scanf("%s", s);
			if(s[0] == 'L')
				op[i].type = 0;
			else if(s[0] == 'b')
			{
				scanf("%s", s);
				op[i].type = 1;
				op[i].x = mp[s];
			}
			else
			{
				op[i].type = 2;
				scanf("%s", s);
				op[i].x = mp[s];
				scanf("%s", s);
				op[i].y = mp[s];
				op[i].i = tot;
				add_edge(op[i].x, op[i].y);
				add_edge(op[i].y, op[i].x);
			}
		}
		memset(vis, 0, sizeof(vis));
		LCA(1);
		for(i = 0; i < m; i++)
		{
			//cout << op[i].type << ' ' << op[i].x << ' ' << op[i].y << endl;
			if(op[i].type == 0)
			{
				printf("%s\n", name[1]);
				pr(1);
			}
			else if(op[i].type == 1)
			{
				if(op[i].x == 1)
				{
					printf("1\n");
				}
				else
				{
					j = fa[op[i].x];
					printf("%d\n", g[j].size() - (j == 1 ? 0 : 1));
				}
			}
			else
			{
				j = e[op[i].i].lca;
				if(j == op[i].x || j == op[i].y)
					j = fa[j];
				printf("%s\n", name[j] + num[j]);
			}
		}
	}
	return 0;
}

