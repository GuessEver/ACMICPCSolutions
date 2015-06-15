#include <cstdio>
#include <cmath>
#include <utility>
#include <queue>
using std::pair;
using std::priority_queue;

const int N = 6666 + 10;

int n, x[N], y[N], z[N];

inline double sqr(int x) { return 1.0 * x * x; }

inline double calc(int i, int j)
{
	if(z[i] == 1 && z[j] == 1) return 0.0;
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

typedef pair<double, int> pir;
priority_queue<pir> Q;
double dist[N];
bool done[N];

double prim()
{
	for(int i = 1; i <= n; i++) dist[i] = 1e10;
	dist[1] = 0.0; double res = 0.0;
	Q.push(std::make_pair(0.0, 1));
	while(!Q.empty())
	{
		int x = Q.top().second; Q.pop();
		if(done[x]) continue;
		res += dist[x]; done[x] = 1;
		for(int i = 1; i <= n; i++) if(i != x)
			if(dist[i] > calc(x, i))
			{
				dist[i] = calc(x, i);
				Q.push(std::make_pair(-dist[i], i));
			}
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
	printf("%.2f\n", prim());
	return 0;
}
