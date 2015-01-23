#include <cstdio>
#include <algorithm>
using std::min;
using std::sort;

struct Point{
	int x, y, a, b;
	void Read()
	{
		scanf("%d%d%d%d", &x, &y, &a, &b);
	}
	void Rotate()
	{
		x -= a; y -= b;
		int t = x;
		x = -y; y = t;
		x += a; y += b;
	}
}a[10], b[10];

int ti[10];
bool flag_ok = 0;
int ans = 0;

bool cmp(Point a, Point b)
{
	if(a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}

long long D(Point a, Point b)
{
	return (long long)(a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool check()
{
	sort(b+1, b+5, cmp);
	for(int i = 2; i <= 4; i++)
		if(b[i].x == b[i-1].x && b[i].y == b[i-1].y) return 0;
	long long k1k2 = (long long)(b[2].y - b[3].y) * (b[4].y - b[1].y) 
									+ (b[2].x - b[3].x) * (b[4].x - b[1].x);
	if(k1k2 != 0) return 0;
	if(D(b[1], b[4]) != D(b[2], b[3])) return 0;
	return D(b[1], b[2]) == D(b[1], b[3]) && D(b[1], b[2]) == D(b[2], b[4]);
}

void dfs(int x)
{
	if(x > 4)
	{
		//for(int i = 1; i <= 4; i++) printf("%d ", ti[i]); puts("");
		for(int i = 1; i <= 4; i++) b[i] = a[i];
		int step = 0;
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= ti[i]; j++) b[i].Rotate();
			step += ti[i];
		}
		if(check())
		{
			if(ans == -1 || ans > step) ans = step;
		}
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		ti[x] = i;
		dfs(x+1);
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		for(int i = 1; i <= 4; i++) a[i].Read();
		flag_ok = 0; ans = -1;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}
