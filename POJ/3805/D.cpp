#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const int N = 100 + 10;
const double eps = 1e-7;

int n, m;
struct Point{
	int x, y;
	void Read() { scanf("%d%d", &x, &y); }
}black[N], white[N];

int sign(int tmp) { return tmp == 0 ? 0 : tmp / abs(tmp); }
int sign(double tmp)
{
	if(fabs(tmp) < eps) return 0;
	return tmp > 0 ? 1 : -1;
}

bool solve1(int x)
{
	int dir = 0;
	for(int i = 1; i <= n; i++)
		if(black[i].x != x)
		{
			dir = sign(black[i].x - x);
			break;
		}
	int bmin = -1, bmax = -1, wmin = -1, wmax = -1;
	for(int i = 1; i <= n; i++)
	{
		if(black[i].x == x)
		{
			if(bmin == -1 || black[i].y < bmin) bmin = black[i].y;
			if(bmax == -1 || black[i].y > bmax) bmax = black[i].y;
		}
		else if(sign(black[i].x - x) != dir) return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		if(white[i].x == x)
		{
			if(wmin == -1 || white[i].y < wmin) wmin = white[i].y;
			if(wmax == -1 || white[i].y > wmax) wmax = white[i].y;
		}
		else if(sign(white[i].x - x) != -dir) return 0;
	}
	return (bmin > wmax || bmax < wmin);
}

bool solve2(int y)
{
	int dir = 0;
	for(int i = 1; i <= n; i++)
		if(black[i].y != y)
		{
			dir = sign(black[i].y - y);
			break;
		}
	int bmin = -1, bmax = -1, wmin = -1, wmax = -1;
	for(int i = 1; i <= n; i++)
	{
		if(black[i].y == y)
		{
			if(bmin == -1 || black[i].x < bmin) bmin = black[i].x;
			if(bmax == -1 || black[i].x > bmax) bmax = black[i].x;
		}
		else if(sign(black[i].y - y) != dir) return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		if(white[i].y == y)
		{
			if(wmin == -1 || white[i].x < wmin) wmin = white[i].x;
			if(wmax == -1 || white[i].x > wmax) wmax = white[i].x;
		}
		else if(sign(white[i].y - y) != -dir) return 0;
	}
	return (bmin > wmax || bmax < wmin);
}

bool solve3(double k, double b)
{
	int dir = 0;
	for(int i = 1; i <= n; i++)
	{
		int tmp = sign(k * black[i].x - black[i].y + b);
		if(tmp != 0)
		{
			dir = tmp;
			break;
		}
	}
	int bmin = -1, bmax = -1, wmin = -1, wmax = -1;
	for(int i = 1; i <= n; i++)
	{
		if(sign(k * black[i].x - black[i].y + b) == 0)
		{
			if(bmin == -1 || black[i].y < bmin) bmin = black[i].y;
			if(bmax == -1 || black[i].y > bmax) bmax = black[i].y;
		}
		else if(sign(k * black[i].x - black[i].y + b) != dir) return 0;
	}
	for(int i = 1; i <= m; i++)
	{
		if(sign(k * white[i].x - white[i].y + b) == 0)
		{
			if(wmin == -1 || white[i].y < wmin) wmin = white[i].y;
			if(wmax == -1 || white[i].y > wmax) wmax = white[i].y;
		}
		else if(sign(k * white[i].x - white[i].y + b) != -dir) return 0;
	}
	return (bmin > wmax || bmax < wmin);
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 1; i <= n; i++) black[i].Read();
		for(int i = 1; i <= m; i++) white[i].Read();
		bool flag = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				if(black[i].x == white[j].x)
					flag |= solve1(black[i].x);
				if(black[i].y == white[j].y)
					flag |= solve2(black[i].y);
				else {
					int by = black[i].y, bx = black[i].x;
					int wy = white[j].y, wx = white[j].x;
					double k = 1.0 * (wy - by) / (wx - bx);
					double b = by - k * bx;
					flag |= solve3(k, b);
				}
			}
		if(flag) puts("YES"); else puts("NO");
	}
	return 0;
}
