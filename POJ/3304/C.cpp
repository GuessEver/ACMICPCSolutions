#include <cstdio>
#include <cmath>
const int N = 100 + 10;
const double EPS = 1e-8;
int n;
struct Point {
	double x, y;
	Point() {}
	Point(const double &_x, const double &_y) { x = _x; y = _y; }
	void Read() {
		scanf("%lf%lf", &x, &y);
	}
	Point operator - (const Point &b) {
		return Point(x - b.x, y - b.y);
	}
	double operator ^ (const Point &b) {
		return x * b.y - y * b.x;
	}
	double Abs() {
		return sqrt(x * x + y * y);
	}
}p[N][2];
struct Line {
	Point s, e;
	Line() {}
	Line(const Point &_s, const Point &_e) { s = _s; e = _e; }
};
int sign(double x) {
	if(fabs(x) < EPS) return 0;
	return x > 0 ? 1 : -1;
}
bool isLineIntersectWithSegment(Line l1, Line l2) {
	return sign((l1.s - l2.s) ^ (l1.e - l2.s)) * sign((l1.s - l2.e) ^ (l1.e - l2.e)) <= 0;
}
bool check(Point s, Point e) {
	if(sign((s - e).Abs()) == 0) return 0;
	for(int i = 1; i <= n; i++)
		if(!isLineIntersectWithSegment(Line(s, e), Line(p[i][0], p[i][1]))) return 0;
	return 1;
}
bool solve() {
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) if(i != j)
			for(int it = 0; it < 2; it++)
				for(int jt = 0; jt < 2; jt++)
					if(check(p[i][it], p[j][jt])) return 1;
	return 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			p[i][0].Read();
			p[i][1].Read();
		}
		puts(solve() || n == 1 ? "Yes!" : "No!");
	}
	return 0;
}
