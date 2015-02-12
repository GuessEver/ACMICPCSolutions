#include <cstdio>
#include <cstring>
#include <queue>
#define sqr(_X) ((_X)*(_X))
using std::queue;

const int N = 1000 + 10;

int n, st, tar;
double l1, l2, maxlen;
double x[N], y[N];
int cap[N][N], dist[N];
bool inQ[N];
queue<int> Q;

void spfa()
{
	memset(dist, 0x3f, sizeof(dist));
	Q.push(st); dist[st] = 0;
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); inQ[x] = 0;
		for(int j = 1; j <= n; j++) 
			if(dist[j] > dist[x] + cap[x][j])
			{
				dist[j] = dist[x] + cap[x][j];
				if(!inQ[j])
				{
					Q.push(j);
					inQ[j] = 1;
				}
			}
	}
	if(dist[tar] != 0x3f3f3f3f) printf("%d\n", dist[tar]);
	else puts("Impossible");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &st, &tar);
		scanf("%lf%lf", &l1, &l2);
		maxlen = sqr(l1 + l2);
		for(int i = 1; i <= n; i++)
			scanf("%lf%lf", &x[i], &y[i]);
		for(int i = 1; i <= n; i++)
		{
			cap[i][i] = 0;
			for(int j = i + 1; j <= n; j++)
			{
				if(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) - maxlen > 1e-7)
					cap[i][j] = cap[j][i] = 0x3f3f3f3f;
				else cap[i][j] = cap[j][i] = 1;
			}
		}
		spfa();
	}
	return 0;
}
