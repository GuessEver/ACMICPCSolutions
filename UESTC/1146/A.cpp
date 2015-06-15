#include <cstdio>
#include <cmath>
#include <algorithm>

const int N = 6666 + 10;

int n, x[N], y[N], z[N];

inline double sqr(int x) { return 1.0 * x * x; }

inline double calc(int i, int j)
{
	if(z[i] == 1 && z[j] == 1) return 0.0;
	return sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
}

double dist[N];
bool done[N];

double prim()
{
	for(int i = 1; i <= n; i++) dist[i] = 1e10;
	dist[1] = 0.0; double res = 0.0;
	for(int i = 1; i <= n; i++)
	{
		int x = -1;
		for(int i = 1; i <= n; i++)
			if(!done[i] && (x == -1 || dist[i] < dist[x])) x = i;
		res += dist[x]; done[x] = 1;
		for(int i = 1; i <= n; i++) if(i != x)
			dist[i] = std::min(dist[i], calc(x, i));
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
