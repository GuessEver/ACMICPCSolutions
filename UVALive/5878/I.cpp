#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

int n;
struct Point{
	int x, y, r;
	void Read() { scanf("%d%d", &x, &y); }
	bool operator < (const Point &b) const
	{
		return r < b.r;
	}
}p[200];
long long dis = 0;

long long DIS(Point &a) 
{
	return 1ll * a.x * a.x + 1ll * a.y * a.y;
}

void randomOrder()
{
	for(int i = 1; i <= n; i++) p[i].r = rand();
	std::sort(p+1, p+1+n);
}

int main()
{
	srand(time(0));
	while(scanf("%d", &n) == 1 && n)
	{
		dis = 0;
		for(int i = 1; i <= n; i++) p[i].Read();
		for(int o = 1; o <= 10000; o++)
		{
			randomOrder();
			Point S; S.x = S.y = 0;
			for(int i = 1; i <= n; i++)
			{
				Point tmp1 = S;
				tmp1.x += p[i].x; tmp1.y += p[i].y;
				Point tmp2 = S;
				tmp2.x -= p[i].x; tmp2.y -= p[i].y;
				if(DIS(tmp1) > DIS(tmp2)) S = tmp1; else S = tmp2;
				if(DIS(S) > dis) dis = DIS(S);
			}
		}
		printf("%.3f\n", sqrt(1.0 * dis));
	}
	return 0;
}
