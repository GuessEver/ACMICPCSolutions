#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
const int inf = 0x3f3f3f3f;
const int N = 500 * 5 + 10;

int n1, n2, m, d;
int g[N][N];
int v[N], h[N];
int S, T;
struct Node{
	int a, idx;
}a[N], b[N];
bool cmp1(const Node &x, const Node &y) { return x.a > y.a; }
bool cmp2(const Node &x, const Node &y) { return x.a < y.a; }

int sap(int x, int flow)
{
	if(x == T) return flow;
	int res = 0;
	for(int i = S; i <= T; i++)
		if(g[x][i] && h[x] == h[i] + 1)
		{
			int t = sap(i, std::min(g[x][i], flow - res));
			res += t; g[x][i] -= t; g[i][x] += t;
			if(res == flow) return res;
			//if(h[S] >= T) return res;
		}
	if(h[S] >= T) return res;
	if((--v[h[x]]) == 0) h[S] = T;
	++v[++h[x]];
	return res;
}
inline int I(const int &x) { return 2 * x - 1; }
inline int O(const int &x) { return 2 * x; }

bool solve(bool flag)
{
	memset(g, 0, sizeof(g));
	memset(v, 0, sizeof(v));
	memset(h, 0, sizeof(h));
	S = 1; T = 2 * (n1 + n2 + 1) + 1;
	for(int i = 1; i <= n1; i++)
		for(int j = 1; j <= n2; j++)
			if(abs(a[i].a - b[j].a) < d)
			{
				g[O(a[i].idx)][I(b[j].idx)] = inf;
				g[O(b[j].idx)][I(a[i].idx)] = inf;
			}
	for(int i = 1; i <= n1; i++) g[I(a[i].idx)][O(a[i].idx)] = 1;
	for(int i = 1; i <= n2; i++) g[I(b[i].idx)][O(b[i].idx)] = 1;
	if(!flag)
	{
		std::sort(a+1, a+1+n1, cmp1); std::sort(b+1, b+1+n2, cmp2);
		for(int i = 1; i <= m; i++) g[S][I(a[i].idx)] = inf;
		for(int i = 1; i <= m; i++) g[O(b[i].idx)][T] = inf;
	}
	else {
		std::sort(a+1, a+1+n1, cmp2); std::sort(b+1, b+1+n2, cmp1);
		for(int i = 1; i <= m; i++) g[O(a[i].idx)][T] = inf;
		for(int i = 1; i <= m; i++) g[S][I(b[i].idx)] = inf;
	}
	v[0] = T;
	int maxflow = 0;
	while(h[S] < T) maxflow += sap(1, inf);
	//printf("flag = %d, res = %d\n",flag, maxflow);
	return maxflow >= m;
}

int main()
{
	scanf("%d%d%d%d", &m, &n1, &n2, &d);
	for(int i = 1; i <= n1; i++) { scanf("%d", &a[i].a); a[i].idx = i + 1; }
	for(int i = 1; i <= n2; i++) { scanf("%d", &b[i].a); b[i].idx = i + n1 + 1; }
	puts((solve(0) || solve(1)) ? "S" : "N");
	return 0;
}

