#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

const int N = 100000 + 10;

int n, m, w;
int a[N], height[N*4], add[N*4];

int query(int p, int l, int r, int a)
{
	if(l == r && l == a) return height[p] + add[p];
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int m = (l + r) / 2;
	if(a <= m) return query(p*2, l, m, a);
	else return query(p*2+1, m+1, r, a);
}

void plus(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		add[p] += c;
		return;
	}
	add[p*2] += add[p];
	add[p*2+1] += add[p];
	add[p] = 0;
	int m = (l + r) / 2;
	if(a <= m) plus(p*2, l, m, a, b, c);
	if(b > m) plus(p*2+1, m+1, r, a, b, c);
}

bool check(int tar)
{
	memset(height, 0, sizeof(height));
	memset(add, 0, sizeof(add));
	for(int i = 1; i <= n; i++)
		plus(1, 1, n, i, i, a[i]);
	int days = 0;
	for(int i = 1; i <= n; i++)
	{
		int now = query(1, 1, n, i);
		if(now >= tar) continue;
		int need = tar - now;
		plus(1, 1, n, i, min(i + w - 1, n), need);
		days += need;
		if(days > m) break;
	}
	return days <= m;
}

int main()
{
	scanf("%d%d%d", &n, &m, &w);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int low = 0, high = 2000000000, ans = 0;
	while(low <= high)
	{
		//printf("%d %d\n", low, high);
		int mid = low + (high - low) / 2;
		if(check(mid)) { low = mid + 1; ans = mid; }
		else high = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
