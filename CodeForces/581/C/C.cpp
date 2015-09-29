#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;
int n, m;
struct Node{
	int a, b;
	bool operator < (const Node &y) const
	{
		return b < y.b;
	}
}a[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].a);
		a[i].b = 10 - a[i].a % 10;
	}
	std::sort(a+1, a+1+n);
	int res = 0;
	for(int i = 1; i <= n; i++)
		while(m && a[i].b && a[i].a < 100)
		{
			m--; a[i].b--;
			a[i].a++;
		}
	for(int i = 1; i <= n && m >= 10; i++)
		while(m >= 10 && a[i].a < 100)
		{
			a[i].a += 10;
			m -= 10;
		}
	for(int i = 1; i <= n; i++) res += a[i].a / 10;
	printf("%d\n", res);
	return 0;
}
