#include <cstdio>
#include <cmath>
#include <algorithm>

const double EPS = 1e-10, INF = 1e20;
const double PI = acos(-1.0);
const int sign(const double &x) {
	if(fabs(x) < EPS) return 0;
	return x < 0 ? -1 : 1;
}
const int dcmp(const double &x, const double &y) {
	return sign(x - y);
}
const double toDegree(const double &alpha) {
	return alpha * 180.0 / PI;
}
const double toRad(const double &alpha) {
	return alpha * PI / 180.0;
}

struct Point {
	double x, y;
	Point() {}
	Point(const double &_x, const double &_y) { x = _x; y = _y; }
	void Read() { scanf("%lf%lf", &x, &y); }
	Point operator + (const Point &b) const {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	double operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	double operator ^ (const Point &b) const {
		return x * b.y - y * b.x;
	}
	bool operator == (const Point &b) const {
		return dcmp(x, b.x) == 0 && dcmp(y, b.y) == 0;
	}
	double Abs() const {
		return sqrt(x * x + y * y);
	}
	Point Rotate(const Point &o, const double &alpha) const {
		Point z = *this - o;
		double nx = z.x * cos(alpha) - z.y * sin(alpha);
		double ny = z.x * sin(alpha) + z.y * cos(alpha);
		return Point(nx, ny) + o;
	}
	double Angle() const {
		return atan2(y, x);
	}
};
typedef Point Vector;
// 单位法向量
const Vector getNormalVector(const Vector &P) {
	double L = P.Abs(); // `L` CANNOT BE `0` !!!!
	return Vector(-P.y / L, P.x / L);
}
// 两向量夹角
const double getAngle(const Vector &a, const Vector &b) {
	return acos(a * b / a.Abs() / b.Abs());
}

struct Line {
	Point s, e;
	Line() {}
	Line(const Point &_s, const Point &_e) { s = _s; e = _e; }
};
typedef Line Segment;
// 判断两直线的关系
const int getRelationBetweenLines(const Line &L1, const Line &L2) {
	if(sign((L1.e - L1.s) ^ (L2.e - L2.s)) == 0) {
		if(sign((L2.s - L1.s) ^ (L2.e - L1.s)) == 0) return 0; // coincidence
		else return 1; // parallel
	}
	return 2; // intersection
}
// 直线交点
const Point getLineIntersection(const Line &L1, const Line &L2) {
	Vector v = L1.e - L1.s, w = L2.e - L2.s;
	Vector u = L1.s - L2.s;
	double t = (w ^ u) / (v ^ w);
	return L1.s + v * t;
}
// 点到直线的距离
const double distanceFromPointToLine(const Point &P, const Line &L) {
	Vector v1 = L.e - L.s, v2 = P - L.s;
	return fabs(v1 ^ v2) / v1.Abs();
}
// 点到直线最近的点
const Point nearestPointToLine(const Point &P, const Line &L) {
	Point P2 = P + getNormalVector(L.e - L.s);
	return getLineIntersection(Line(P, P2), L);
}
// 点到线段的距离
const double distanceFromPointToSegment(const Point &P, const Segment &L) {
	if(L.s == L.e) return (P - L.s).Abs();
	Vector v1 = L.e - L.s, v2 = P - L.s, v3 = P - L.e;
	if(sign(v1 * v2) < 0) return v2.Abs();
	if(sign(v1 * v3) > 0) return v3.Abs();
	return fabs(v1 ^ v2) / v1.Abs();
}
// 点到线段最近的点
const Point nearestPointToSegment(const Point &P, const Segment &L) {
	if(L.s == L.e) return L.s;
	Vector v1 = L.e - L.s, v2 = P - L.s, v3 = P - L.e;
	if(sign(v1 * v2) < 0) return L.s;
	if(sign(v1 * v3) > 0) return L.e;
	return nearestPointToLine(P, L);
}
// 判断点在线端上
const bool isPointOnSegment(const Point &P, const Segment &L) {
	Vector v1 = P - L.s, v2 = P - L.e;
	return sign(v1 ^ v2) == 0 && sign(v1 * v2) < 0;
}
// 判断线段相交
const bool isSegmentIntersectWithSegment(const Segment &L1, const Segment &L2) {
	return std::max(L1.s.x, L1.e.x) >= std::min(L2.s.x, L2.e.x)
		&& std::max(L1.s.y, L1.e.y) >= std::min(L2.s.y, L2.e.y)
		&& std::max(L2.s.x, L2.e.x) >= std::min(L1.s.x, L1.e.x)
		&& std::max(L2.s.y, L2.e.y) >= std::min(L1.s.y, L1.e.y)
		&& sign((L1.e - L1.s) ^ (L2.s - L1.s)) * sign((L1.e - L1.s) ^ (L2.e - L1.s)) <= 0
		&& sign((L2.e - L2.s) ^ (L1.s - L2.s)) * sign((L2.e - L2.s) ^ (L1.e - L2.s)) <= 0;
}
const bool isLineIntersectWithSegment(const Line &L1, const Segment &L2) {
	return sign((L1.s - L2.s) ^ (L1.e - L2.s)) * sign((L1.s - L2.e) ^ (L1.e - L2.e)) <= 0;
}

int main() {
	int T; scanf("%d", &T);
	puts("INTERSECTING LINES OUTPUT");
	while(T--) {
		Line L1, L2;
		L1.s.Read(); L1.e.Read();
		L2.s.Read(); L2.e.Read();
		int tmp = getRelationBetweenLines(L1, L2);
		if(tmp == 0) puts("LINE");
		else if(tmp == 1) puts("NONE");
		else {
			Point A = getLineIntersection(L1, L2);
			printf("POINT %.2f %.2f\n", A.x, A.y);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
