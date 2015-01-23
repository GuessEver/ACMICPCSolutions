#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::min;
using std::max;

const int N = 1500 + 10;

int n;
struct Point{
	long long x, y;
	void Read() { scanf("%lld%lld", &x, &y); }
}a[N], b[N], st, ed;

long long cross(Point a, Point b, Point c, Point d)
{
	long long x1 = b.x - a.x;
	long long y1 = b.y - a.y;
	long long x2 = d.x - c.x;
	long long y2 = d.y - c.y;
	long long tmp = x1 * y2 - x2 * y1;
	if(tmp > 0) tmp = 1;
	else if(tmp < 0) tmp = -1;
	return tmp;
}

bool online(Point p1, Point p2, Point q)
{
	if(min(p1.x, p2.x) <= q.x && q.x <= max(p1.x, p2.y) &&
			min(p1.y, p2.y) <= q.y && q.y <= max(p1.y, p2.y) &&
			cross(p1, p2, p1, q) == 0)
		return 1;
	return 0;
}

bool check(Point p1, Point p2, Point q1, Point q2) // a1-b1    a2-b2
{
	if(cross(p1,q1,p1,p2) * cross(p1,p2,p1,q2) > 0 
			&& cross(q1,p1,q1,q2) * cross(q1,q2,q1,p2) > 0) return 1;
	if(online(p1,p2,q1) || online(p1,p2,q2) 
			|| online(q1,q2,p1) || online(q1,q2,p2)) return 1;
	return 0;
}

int calc(Point tar)
{
	ed.x = st.x + (tar.x - st.x) * 50000;
	ed.y = st.y + (tar.y - st.y) * 50000;
	//printf("%lld %lld %lld %lld\n", st.x, st.y, ed.x, ed.y);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(check(st, ed, a[i], b[i])) cnt++;
		//printf("cnt = %d\n", cnt);
	}
	return cnt;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			a[i].Read();
			b[i].Read();
		}
		st.Read();
		int ans = 1;
		for(int i = 1; i <= n; i++)
		{
			ans = std::max(ans, calc(a[i]));
			ans = std::max(ans, calc(b[i]));
		}
		printf("%d\n", ans);
	}
	return 0;
}
