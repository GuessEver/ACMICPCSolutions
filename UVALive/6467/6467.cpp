#include <cstdio>
#include <cstring>

const int N = 1000 + 10;

int n, m;
bool cap[N][N];
int in[N], out[N];
int ord[N];
bool caled[N];

int cal(int x)
{
	if(!in[x]) return ord[x] = 1;
	if(caled[x]) return ord[x];
	caled[x] = 1;
	int d = 0, cnt = 0;
	for(int i = 1; i <= n; i++) if(cap[i][x])
	{
		int t = cal(i);
		if(t > d)
		{
			d = t; cnt = 0;
		}
		if(t == d) cnt++;
	}
	if(cnt > 1) d++;
	return ord[x] = d;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		cap[u][v] = 1;
		in[v]++;
	}
	//for(int i = 1; i <= n; i++) if(!in[i]) ord[i] = 1;
	printf("%d\n", cal(n));
	//for(int i = 1; i <= n; i++)printf("%d ", ord[i]); puts("");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int k; scanf("%d", &k);
		printf("%d ", k);
		memset(cap, 0, sizeof(cap));
		memset(in, 0, sizeof(in));
		memset(ord, 0, sizeof(ord));
		memset(caled, 0, sizeof(caled));
		solve();
	}
	return 0;
}
