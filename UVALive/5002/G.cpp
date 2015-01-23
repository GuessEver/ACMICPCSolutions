#include <cstdio>
#include <cstring>

const int N = 1000 + 10;
const long long mod = 1000000000 + 7;

int n, in[N], root;
struct Link{int y; Link *next;}*head[N];
int num[N];
long long ans[N];
long long C[N][N];

void pre(int maxp)
{
	for(int i = 1; i <= maxp; i++) C[i][0] = 1;
	for(int i = 1; i <= maxp; i++) C[i][i] = 1;
	for(int i = 2; i <= maxp; i++)
		for(int j = 1; j < i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
}

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x)
{
	num[x] = 1;
	for(Link *p = head[x]; p; p = p -> next)
	{
		dfs(p -> y);
		num[x] += num[p->y];
	}
}

void calc(int x)
{
	ans[x] = 1;
	int tot = num[x] - 1;
	for(Link *p = head[x]; p; p = p -> next)
	{
		calc(p -> y);
		ans[x] = ans[x] * ans[p->y] % mod * C[tot][num[p->y]] % mod;
		tot -= num[p->y];
	}
}

int main()
{
	pre(1000);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(head, 0, sizeof(head));
		memset(in, 0, sizeof(in));
		scanf("%d", &n);
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y);
			in[y] = 1;
		}
		for(int i = 1; i <= n; i++) if(!in[i]) {root = i; break;}
		dfs(root);
		//for(int i = 1; i <= n; i++) printf("%d : %d\n", i, num[i]);
		calc(root);
		printf("Case %d: %lld\n", cas, ans[root] % mod);
	}
	return 0;
}
