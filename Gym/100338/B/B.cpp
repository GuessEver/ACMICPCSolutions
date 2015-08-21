#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
const double EPS = 1e-9;
inline double sqr(const double r) { return r * r; }
inline int dcmp(double k) { return k < -EPS ? -1 : k > EPS ? 1 : 0; }
inline double mysqrt(double x) { return sqrt(std::max(0.0, x)); }
struct Point {
	double x, y;
	Point () { x = y = 0.0; }
	Point (double _x, double _y) { x = _x; y = _y; }
	bool Read()
	{
		//x = rand()%10 + 1.0; y = rand()%10 + 1.0; return 1;
		return scanf("%lf%lf", &x, &y) == 2;
	}
	bool operator == (const Point &b)
	{
		return dcmp(x - b.x) == 0 && dcmp(y - b.y) == 0;
	}
	double Abs()
	{
		return sqrt(x * x + y * y);
	}
}zero;

int circle_cross_line(const Point a, const Point b, const Point o, const double r, Point ret[])
{
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx * dx + dy * dy;
	double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
	double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
	double delta = B * B - 4 * A * C;
	int num = 0;
	if(dcmp(delta) >= 0)
	{
		double t1 = (-B - mysqrt(delta)) / (2 * A);
		double t2 = (-B + mysqrt(delta)) / (2 * A);
		if(dcmp(t1 - 1) <= 0 && dcmp(t1) >= 0)
			ret[num++] = Point(x1 + t1 * dx, y1 + t1 * dy);
		if(dcmp(t2 - 1) <= 0 && dcmp(t2) >= 0)
			ret[num++] = Point(x1 + t2 * dx, y1 + t2 * dy);
	}
	return num;
}

Point o, ret[10]; double r;
bool solve(const Point p11, const Point p12, const Point p21, const Point p22)
{
	// make circle from p11 & p21
	o = Point((p11.x + p21.x) / 2.0, (p11.y + p21.y) / 2.0);
	r = Point(p11.x - p21.x, p11.y - p21.y).Abs() / 2.0 + 0.001;
	// get number of crossed point between the circle and p12 & p22
	int tmp1 = circle_cross_line(p11, p12, o, r, ret);
	//printf("> (%.6f, %.6f) %.6f [%d]\n", o.x, o.y, r, tmp1);
	if(tmp1 != 1 || ret[0] == p11 || ret[0] == p12) return 0;
	int tmp2 = circle_cross_line(p21, p22, o, r, ret);
	//printf("> (%.6f, %.6f) %.6f [%d]\n", o.x, o.y, r, tmp2);
	if(tmp2 != 1 || ret[0] == p21 || ret[0] == p22) return 0;
	return 1;
}


Point p11, p12, p21, p22;
int main()
{
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	//srand(time(0));
	while(p11.Read() && p12.Read() && p21.Read() && p22.Read())
	{
		//printf("(%.6f, %.6f) (%.6f, %.6f) (%.6f, %.6f) (%.6f, %.6f)\n", p11.x, p11.y, p12.x, p12.y, p21.x, p21.y, p22.x, p22.y);
		if(p11 == zero && p12 == zero && p21 == zero && p22 == zero) break;
		if(solve(p11, p12, p21, p22) || solve(p11, p12, p22, p21)
				|| solve(p12, p11, p21, p22) || solve(p12, p11, p22, p21))
			printf("%.6f %.6f %.6f\n", o.x, o.y, r);
		//int tmp1 = circle_cross_line(p11, p12, o, r, ret);
		//printf("[%d]> ", tmp1);
		//for(int i = 0; i < tmp1; i++) printf("(%.6f, %.6f) ", ret[i].x, ret[i].y); puts("");
		//int tmp2 = circle_cross_line(p21, p22, o, r, ret);
		//printf("[%d]> ", tmp2);
		//for(int i = 0; i < tmp1; i++) printf("(%.6f, %.6f) ", ret[i].x, ret[i].y); puts("");
		//if(tmp1 != 1 || tmp2 != 1) while(1);
	}
	return 0;
}
