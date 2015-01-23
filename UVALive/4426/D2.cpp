#include <cstdio>
#include <cmath>

struct Point{
	int x, y;
	Point operator - (const Point &b) const
	{
		Point res;
		res.x = x - b.x;
		res.y = y - b.y;
		return res;
	}
	double operator * (const Point &b) const
	{
		return x * b.y - y * b.x;
	}
}p[110];
typedef Point Vector;
int n;

void center(int i, int j, int k, double &x, double &y)
{
	x = (p[i].x + p[j].x + p[k].x) / 3.0;
	y = (p[i].y + p[j].y + p[k].y) / 3.0;
}
double Area(int i, int j, int k)
{
	Vector A1 = p[i] - p[j];
	Vector A2 = p[i] - p[k];
	return fabs(A1 * A2) / 2;
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) 
			scanf("%d%d", &p[i].x, &p[i].y);
		double X = 0, Y = 0, S = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++) if(i!=j)
				for(int k = 1; k <= n; k++) if(j!=k && i!=k)
				{
					double area = Area(i, j, k);
					double cx, cy;
					center(i, j, k, cx, cy);
					X += area * cx;
					Y += area * cy;
					S += area;
				}
		printf("Stage #%d: %.6lf %.6lf\n", ++cas, X/S, Y/S);
	}
	return 0;
}
