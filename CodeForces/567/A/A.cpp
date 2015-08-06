#include <cstdio>
#include <cstdlib>
#include <algorithm>

const int N = 100000 + 10;

int n;
struct Node{
	int x, min, max, i;
	bool operator < (const Node &b) const
	{
		return x < b.x;
	}
}a[N];

bool cmp(const Node &x, const Node &y)
{
	return x.i < y.i;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].x);
		a[i].i = i;
	}
	std::sort(a+1, a+1+n);
	a[1].min = abs(a[2].x - a[1].x);
	a[n].max = a[1].max = abs(a[n].x - a[1].x);
	a[n].min = abs(a[n-1].x - a[n].x);
	for(int i = 2; i < n; i++)
	{
		a[i].min = std::min(abs(a[i+1].x - a[i].x), abs(a[i-1].x - a[i].x));
		a[i].max = std::max(abs(a[1].x - a[i].x), abs(a[n].x - a[i].x));
	}
	std::sort(a+1, a+1+n, cmp);
	for(int i = 1; i <= n; i++) printf("%d %d\n", a[i].min, a[i].max);
	return 0;
}
