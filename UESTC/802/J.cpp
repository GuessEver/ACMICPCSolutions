#include <cstdio>

const int N = 50000 + 10;

struct Point{
	int x, y;
	void Read() { scanf("%d%d", &x, &y); }
	Point() {}
	Point(int a, int b) { x = a; y = b; }
}a[N];
typedef Point Vector;
int n;

Vector getLine(int i, int j)
{
	return Vector(a[j].x - a[i].x, a[j].y - a[i].y);
}

bool par(Vector a, Vector b)
{
	return 1ll * a.x * b.y == 1ll * a.y * b.x;
}

bool solve(int start, int end)
{
	Vector line = getLine(start, end);
	int cnt = 0, k = n;
	for(int i = 1; i <= n; i++)
	{
		Vector now = getLine(start, i);
		if(par(line, now)) cnt++;
		else k = i;
	}
	if(cnt == n - 1)
	{
		printf("%d %d\n", a[k].x, a[k].y);
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) a[i].Read();
	if(!solve(1, 2)) if(!solve(1, 3)) solve(2, 3);
	return 0;
}
