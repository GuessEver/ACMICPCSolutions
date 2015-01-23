#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using std::stack;
using std::min;

const int N = 10000 + 10;

int n, m;
struct Link{int y; Link *next;}*head[N];
int now[N], low[N], dfstime, hash[N], inst[N];
int number, belong[N];
stack <int> st;
int in[N];

void inLink(int x, int y)
{
	Link *p = new Link;
	p -> y = y;
	p -> next = head[x];
	head[x] = p;
}

void dfs(int x)
{
	now[x] = low[x] = ++dfstime;
	hash[x] = 1;
	st.push(x); inst[x] = 1;
	for(Link *p = head[x]; p; p = p -> next)
	{
		int i = p->y;
		if(!hash[i])
		{
			dfs(i);
			low[x] = min(low[x], low[i]);
		}
		else if(inst[i]) low[x] = min(low[x], now[i]);
	}
	if(low[x] == now[x])
	{
		while(!st.empty())
		{
			int u = st.top();
			st.pop(); inst[u] = 0;
			belong[u] = number;
			if(u == x) break;
		}
		number++;
	}
}
void tarjan()
{
	for(int i = 1; i <= n; i++)
		if(!hash[i]) dfs(i);
	if(!st.empty())//栈中剩下的也是一个强连通分量
	{
		while(!st.empty())
		{
			int u = st.top();
			st.pop();
			belong[u] = number;
		}
		number++;
	}
	/*for(int k = 0; k < number; k++)
	{
		printf("number = %d:    ", k);
		for(int i = 1; i <= n; i++)
			if(belong[i] == k) printf("%d ", i);
		printf("\n");
	}printf("\n\n");*/
}

int main()
{
	freopen("J.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case %d: ", cas);
		memset(hash, 0, sizeof(hash));
		memset(now, 0, sizeof(now));
		memset(low, 0, sizeof(low));
		memset(inst, 0, sizeof(inst));
		memset(belong, 0, sizeof(belong));
		memset(head, 0, sizeof(head));
		while(!st.empty()) st.pop();
		number = 0;
		dfstime = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			inLink(x, y);
		}
		tarjan();
		memset(in, 0, sizeof(in));
		for(int i = 1; i <= n; i++)
			for(Link *p = head[i]; p; p = p->next)
				if(belong[i] != belong[p->y])
					in[belong[p->y]]++;
		int ans = 0;
		for(int i = 0; i < number; i++) if(!in[i]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
