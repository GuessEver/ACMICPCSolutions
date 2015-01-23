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

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) 
			scanf("%d%d", &p[i].x, &p[i].y);
		p[n+1] = p[1];
		double X = 0, Y = 0, S = 0;
		for(int i = 1; i <= n; i++)
		{
			double area = p[i] * p[i+1];
			double cx = (p[i].x + p[i+1].x) / 3.0;
			double cy = (p[i].y + p[i+1].y) / 3.0;
			X += cx * area;
			Y += cy * area;
			S += area;
		}
		if(S < 0) { S = -S; X = -X; Y = -Y; }
		printf("Stage #%d: %.6lf %.6lf\n", ++cas, X/S, Y/S);
	}
	return 0;
}
