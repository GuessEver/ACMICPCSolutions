#include <cstdio>
#include <algorithm>

int n, m;
struct Node{
	int x, idx;
	bool operator < (const Node &b) const
	{
		return x < b.x;
	}
}a[200];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].x);
		a[i].idx = i;
	}
	std::sort(a+1, a+1+n);
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(m < a[i].x) break;
		m -= a[i].x;
		cnt++;
	}
	printf("%d\n", cnt);
	if(cnt == 0) return 0;
	for(int i = 1; i < cnt; i++) printf("%d ", a[i].idx);
	printf("%d\n", a[cnt].idx);
	return 0;
}
