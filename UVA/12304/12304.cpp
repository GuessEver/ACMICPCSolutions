#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using std::vector;

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
	bool operator < (const Point &b) const {
		return dcmp(x, b.x) < 0 || (dcmp(x, b.x) == 0 && dcmp(y, b.y) < 0);
	}
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
const double getDistanceFromPointToLine(const Point &P, const Line &L) {
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
const bool isSegmentIntersection(const Segment &L1, const Segment &L2) {
	return std::max(L1.s.x, L1.e.x) >= std::min(L2.s.x, L2.e.x)
		&& std::max(L1.s.y, L1.e.y) >= std::min(L2.s.y, L2.e.y)
		&& std::max(L2.s.x, L2.e.x) >= std::min(L1.s.x, L1.e.x)
		&& std::max(L2.s.y, L2.e.y) >= std::min(L1.s.y, L1.e.y)
		&& sign((L1.e - L1.s) ^ (L2.s - L1.s)) * sign((L1.e - L1.s) ^ (L2.e - L1.s)) <= 0
		&& sign((L2.e - L2.s) ^ (L1.s - L2.s)) * sign((L2.e - L2.s) ^ (L1.e - L2.s)) <= 0;
}
// 判断直线和线段相交
const bool isLineSegmentIntersection(const Line &L1, const Segment &L2) {
	return sign((L1.s - L2.s) ^ (L1.e - L2.s)) * sign((L1.s - L2.e) ^ (L1.e - L2.e)) <= 0;
}

struct Circle {
	Point o; double r;
	Circle() {}
	Circle(const Point &_o, const double &_r) { o = _o; r = _r; }
	Point getPoint(const double &alpha) const {
		return Point(o.x + r * cos(alpha), o.y + r * sin(alpha));
	}
};
// 直线和圆的交（切）点，返回交点个数，p1和p2为两个交点
const int getLineCircleIntersection(const Line &L, const Circle &C, Point &p1, Point &p2) {
	double d = getDistanceFromPointToLine(C.o, L);
	if(dcmp(d, C.r) > 0) return 0;
	Point P = nearestPointToLine(C.o, L);
	if(dcmp(d, C.r) == 0) {
		p1 = p2 = P;
		return 1;
	}
	Vector v = L.e - L.s; v = v / v.Abs();
	double length = sqrt(C.r * C.r - d * d);
	p1 = P + v * length; p2 = P - v * length;
	return 2;
}
// 两个圆的交点，返回交点个数，p1和p2为两个交点
const int getCircleIntersection(const Circle &C1, const Circle &C2, Point &p1, Point &p2) {
	double d = (C1.o - C2.o).Abs();
	if(sign(d) == 0) {
		if(dcmp(C1.r, C2.r) == 0) return -1; // 重合
		return 0;
	}
	if(dcmp(C1.r + C2.r, d) < 0) return 0;
	if(dcmp(fabs(C1.r - C2.r), d) > 0) return 0;
	double a = (C2.o - C1.o).Angle();
	double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
	p1 = C1.getPoint(a - da); p2 = C1.getPoint(a + da);
	if(p1 == p2) return 1; else return 2;
}
const int getRelationBetweenCircles(const Circle &C1, const Circle &C2) {
	double d = (C1.o - C2.o).Abs(), r1 = C1.r, r2 = C2.r;
	if(sign(d) == 0) {
		// 0 重合 - d == 0 && r1 == r2
		if(dcmp(r1, r2) == 0) return 0;
		// 1 同心圆 - d == 0 && r1 != r2
		else return 1;
	}
	// 2 内含 - |r1 - r2| > d
	if(dcmp(fabs(r1 - r2), d) > 0) return 2;
	// 3 内切 - |r1 - r2| == d
	if(dcmp(fabs(r1 - r2), d) == 0) return 3;
	// 4 相交 - r1 + r2 > d && |r1 - r2| < d
	if(dcmp(r1 + r2, d) > 0 && dcmp(fabs(r1 - r2), d) < 0) return 4;
	// 5 外切 - r1 + r2 == d
	if(dcmp(r1 + r2, d) == 0) return 5;
	// 6 相离 - r1 + r2 < d
	if(dcmp(r1 + r2, d) < 0) return 6;
}

// 多边形的有向面积
const double getPolygonArea(const Point *poly, const int &n) {
	double area = 0;
	for(int i = 1; i < n - 1; i++)
		area += (poly[i] - poly[0]) ^ (poly[i+1] - poly[0]);
	return area / 2.0;
}
// 判断点在多边形内
const int isPointInPolygon(const Point &p, const Point *poly, const int &n) {
	int wn = 0;
	for(int i = 0; i < n; i++) {
		if(isPointOnSegment(p, Segment(poly[i], poly[(i+1)%n]))) return 2; // on border
		int k = sign((poly[(i+1)%n] - poly[i]) ^ (p - poly[i]));
		int d1 = sign(poly[i].y - p.y);
		int d2 = sign(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0) wn++;
		if(k < 0 && d2 <= 0 && d1 > 0) wn--;
	}
	if(wn != 0) return 1; // inside
	return 0; // outside
}
// 三角形外接圆
const Circle getCircumscribedCircle(const Point &A, const Point &B, const Point &C) {
	Point AB = (A + B) / 2, AC = (A + C) / 2;
	Vector NAB = getNormalVector(B - A);
	Vector NAC = getNormalVector(C - A);
	Point O = getLineIntersection(Line(AB, AB + NAB), Line(AC, AC + NAC));
	return Circle(O, (O - A).Abs());
}
// 角BAC的角平分线
const Line getAngleDividingLine(const Point &B, const Point &A, const Point &C) {
	Vector AB = B - A, AC = C - A;
	return Line(A, C.Rotate(A, ((B - A).Angle() - (C - A).Angle()) / 2));
}
// 三角形内接圆
const Circle getInscribedCircle(const Point &A, const Point &B, const Point &C) {
	Line BAC = getAngleDividingLine(B, A, C);
	Line ABC = getAngleDividingLine(A, B, C);
	Point O = getLineIntersection(BAC, ABC);
	return Circle(O, getDistanceFromPointToLine(O, Line(B, C)));
}

char op[1000];
int main() {
	while(scanf("%s", op) == 1) {
		if(!strcmp(op, "CircumscribedCircle")) {
			Point A, B, C; A.Read(); B.Read(); C.Read();
			Circle O = getCircumscribedCircle(A, B, C);
			printf("(%.6f,%.6f,%.6f)\n", O.o.x, O.o.y, O.r);
		}
		else if(!strcmp(op, "InscribedCircle")) {
			Point A, B, C; A.Read(); B.Read(); C.Read();
			Circle O = getInscribedCircle(A, B, C);
			printf("(%.6f,%.6f,%.6f)\n", O.o.x, O.o.y, O.r);
		}
		else if(!strcmp(op, "TangentLineThroughPoint")) {
			Circle C; C.o.Read(); scanf("%lf", &C.r);
			Point P; P.Read();
			double d = (C.o - P).Abs();
			vector<double> res; res.clear();
			if(dcmp(d, C.r) < 0) {}
			else if(dcmp(d, C.r) == 0) {
				double ang = getNormalVector(P - C.o).Angle();
				if(sign(ang) < 0) ang += PI;
				res.push_back(toDegree(ang));
			}
			else {
				double ang = asin(C.r / (C.o - P).Abs());
				double ang1 = (C.o.Rotate(P, +ang) - P).Angle();
				double ang2 = (C.o.Rotate(P, -ang) - P).Angle();
				if(sign(ang1) < 0) ang1 += PI;
				if(sign(ang2) < 0) ang2 += PI;
				if(dcmp(ang1, ang2) > 0) std::swap(ang1, ang2);
				res.push_back(toDegree(ang1));
				res.push_back(toDegree(ang2));
			}
			std::sort(res.begin(), res.end());
			printf("[");
			for(vector<double>::iterator it = res.begin(); it != res.end(); it++)
				printf("%.6f%s", *it, it != res.end() - 1 ? "," : "");
			puts("]");
		}
		else if(!strcmp(op, "CircleThroughAPointAndTangentToALineWithRadius")) {
			Circle C; C.o.Read();
			Line L; L.s.Read(); L.e.Read();
			scanf("%lf", &C.r);
			vector<Point> res; res.clear();
			Vector v = getNormalVector(L.e - L.s) * C.r;
			Line L1(L.s + v, L.e + v), L2(L.s - v, L.e - v);
			Point p1, p2;
			int tmp = getLineCircleIntersection(L1, C, p1, p2);
			if(tmp >= 1) res.push_back(p1);
			if(tmp == 2) res.push_back(p2);
			tmp = getLineCircleIntersection(L2, C, p1, p2);
			if(tmp >= 1) res.push_back(p1);
			if(tmp == 2) res.push_back(p2);
			std::sort(res.begin(), res.end());
			printf("[");
			for(vector<Point>::iterator it = res.begin(); it != res.end(); it++)
				printf("(%.6f,%.6f)%s", it->x, it->y, it != res.end() - 1 ? "," : "");
			puts("]");
		}
		else if(!strcmp(op, "CircleTangentToTwoLinesWithRadius")) {
			Line L1; L1.s.Read(); L1.e.Read();
			Line L2; L2.s.Read(); L2.e.Read();
			double r; scanf("%lf", &r);
			vector<Point> res; res.clear();
			Vector v1 = getNormalVector(L1.e - L1.s) * r;
			Vector v2 = getNormalVector(L2.e - L2.s) * r;
			Line L11(L1.s + v1, L1.e + v1), L12(L1.s - v1, L1.e - v1);
			Line L21(L2.s + v2, L2.e + v2), L22(L2.s - v2, L2.e - v2);
			res.push_back(getLineIntersection(L11, L21));
			res.push_back(getLineIntersection(L11, L22));
			res.push_back(getLineIntersection(L12, L21));
			res.push_back(getLineIntersection(L12, L22));
			std::sort(res.begin(), res.end());
			printf("[");
			for(vector<Point>::iterator it = res.begin(); it != res.end(); it++)
				printf("(%.6f,%.6f)%s", it->x, it->y, it != res.end() - 1 ? "," : "");
			puts("]");
		}
		else if(!strcmp(op, "CircleTangentToTwoDisjointCirclesWithRadius")) {
			Circle C1, C2;
			C1.o.Read(); scanf("%lf", &C1.r);
			C2.o.Read(); scanf("%lf", &C2.r);
			double r; scanf("%lf", &r);
			vector<Point> res; res.clear();
			C1.r += r; C2.r += r;
			Point p1, p2;
			int tmp = getCircleIntersection(C1, C2, p1, p2);
			if(tmp >= 1) res.push_back(p1);
			if(tmp == 2) res.push_back(p2);
			std::sort(res.begin(), res.end());
			printf("[");
			for(vector<Point>::iterator it = res.begin(); it != res.end(); it++)
				printf("(%.6f,%.6f)%s", it->x, it->y, it != res.end() - 1 ? "," : "");
			puts("]");
		}
	}
	return 0;
}
