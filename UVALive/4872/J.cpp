#include <cstdio>
#include <algorithm>
#include <cmath>

const int N = 1000 + 10;

struct EG{
	int from, to;
	double value;
	EG() {}
	EG(int x, int y, double z)
	{
		from = x; to = y;
		value = z;
	}
	bool operator < (const EG &b) const
	{
		return value < b.value;
	}
}edge[N*N];
struct Point{
	int x, y;
}p[N];
int n, L;
int f[N];

double Dis(Point a, Point b)
{
	return sqrt(1.0*(a.x-b.x)*(a.x-b.x) + 1.0*(a.y-b.y)*(a.y-b.y));
}

int getroot(int x) { return f[x] == x ? x : f[x] = getroot(f[x]); }

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
		L = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= n; j++)
				edge[L++] = EG(i, j, Dis(p[i], p[j]));
		std::sort(edge, edge+L);
		for(int i = 1; i <= n; i++) f[i] = i;
		double res = 0;
		for(int i = 0; i < L; i++)
		{
			if(getroot(edge[i].from) == getroot(edge[i].to)) continue;
			res += edge[i].value;
			f[getroot(edge[i].from)] = getroot(edge[i].to);
		}
		printf("%.2lf\n", res);
	}
	return 0;
}
