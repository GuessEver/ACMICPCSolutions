#include <cstdio>
#include <cmath>
#include <algorithm>
#define sqr(__x) ((__x)*(__x))

struct Node{
	int x, y;
	int vx, vy;
	void Read()
	{ scanf("%d%d%d%d", &x, &y, &vx, &vy); }
}boat[10];
int n, px, py, pv, idx[10];

double back(double x, double y, int v, int xx, int yy)
{
	double dis = sqrt(1.0 * sqr(x - xx) + sqr(y - yy));
	return dis / v;
}

double go(double &x, double &y, int v, int x1, int y1, int vx, int vy, double pre)
{
	double x0 = x1 + vx * pre;
	double y0 = y1 + vy * pre;
	double a = sqr(vx) + sqr(vy) - sqr(v);
	double b = 2 * vx * (x0 - x) + 2 * vy * (y0 - y);
	double c = sqr(x0 - x) + sqr(y0 - y);
	double delta = sqr(b) - 4 * a * c;
	double t  = (-b + sqrt(delta)) / (2 * a);
	double t2 = (-b - sqrt(delta)) / (2 * a);
	if(t < t2) t = t2;
	t += 1;
	x = x0 + t * vx;
	y = y0 + t * vy;
	//printf("a = %.3lf, b = %.3lf, c = %.3lf\n", a, b, c);
	return t;
}

double solve()
{
	double x = px, y = py; int v = pv;
	double ti = 0;
	for(int t = 1; t <= n; t++)
	{
		int i = idx[t];
		double tmp = go(x, y, v, boat[i].x, boat[i].y, boat[i].vx, boat[i].vy, ti);
		//printf("tmp = %.7lf\n", tmp);
		//printf("(%.5lf , %.5lf)\n", x, y);
		ti += tmp;
	}
	return ti + back(x, y, v, px, py);
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++) boat[i].Read();
		scanf("%d%d%d", &px, &py, &pv);
		for(int i = 1; i <= n; i++) idx[i] = i;
		double TT = 1e200;
		do{
			double tmp = solve();
			if(tmp < TT) TT = tmp;
			//printf("%.7lf  ->   %.7lf\n", tmp, TT);
		}while(std::next_permutation(idx+1, idx+1+n));
		int T = ceil(TT * 3600);
		int H = T / 3600;
		int M = (T - H * 3600) / 60;
		int S = T - H * 3600 - M * 60;
		printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n", ++cas, H, M, S);
	}
	return 0;
}
