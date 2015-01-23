#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int N = 50000 + 10;

int n, v[N], root;
struct Link{int y, z; Link *next;}*head[N], *ask[N];
int vis[N], out[N];
int pos[N*2+10];
int List[N*2+10], L;
int f[N];
int father;
int flag[N*2+10];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}
void inAsk(int x, int y, int z)
{
	Link *p = new Link;
	p -> y = y;
	p -> z = z;
	p -> next = ask[x];
	ask[x] = p;
}

void dfs(int x)
{
	vis[x] = 1;
	//printf("%d ", x);
	pos[x+N] = L; List[L++] = x;
	for(Link *p = head[x]; p; p = p -> next) if(!vis[p->y])
		dfs(p -> y);
	//printf("%d ", -x);
	pos[-x+N] = L; List[L++] = -x;
}

int getroot(int x) {return f[x] == x ? x : f[x] = getroot(f[x]);}

void LCA(int x)
{
	vis[x] = 1;
	f[x] = x;
	for(Link *p = ask[x]; p; p = p ->next)
		if(vis[p->y])
		{
			int father = getroot(p->y);
			int c = p -> z;
			flag[pos[father+N]] += 2*c;
			v[father] -= c;
			//printf("%d %d %d\n", x, p->y, father);
		}
	for(Link *p = head[x]; p; p = p -> next)
		if(!vis[p->y])
		{
			LCA(p->y);
			f[p->y] = x;
		}
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(head, 0, sizeof(head));
		memset(ask, 0, sizeof(ask));
		memset(vis, 0, sizeof(vis));
		memset(out, 0, sizeof(out));
		memset(v, 0, sizeof(v));
		memset(pos, 0, sizeof(pos));
		memset(flag, 0, sizeof(flag));
		L = 0;
		scanf("%d", &n);
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			x++; y++;
			inLink(x, y); inLink(y, x);
			out[x]++; out[y]++;
		}
		for(int i = 1; i <= n; i++) 
			if(out[i] == 1){root = i; break;}
		dfs(root);
		//printf("root = %d\n", root);
		//for(int i = 0; i < L; i++) printf("%d ", List[i]); puts("");
		int q; scanf("%d", &q);
		while(q--)
		{
			int a, b, c; 
			scanf("%d%d%d", &a, &b, &c);
			a++; b++;
			if(a == b) v[a] += c;
			else{
				inAsk(a, b, c);
				inAsk(b, a, c);
				flag[pos[a+N]+1] -= c;
				flag[pos[b+N]+1] -= c;
			}
		}
		memset(vis, 0, sizeof(vis));
		LCA(root);
		int add = 0;
		for(int i = 0; i < L; i++)
		{
			add += flag[i];
			int idx = abs(List[i]);
			int sign = List[i] / idx;
			v[idx] += sign * add;
		}
		printf("Case #%d:\n", cas);
		for(int i = 1; i <= n; i++) printf("%d\n", v[i]);
	}
	return 0;
}
