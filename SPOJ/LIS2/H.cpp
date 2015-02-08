#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define lowbit(__x) ((__x)&(-(__x)))

const int N = 100000 + 10;

struct Node{int x, y, z;}a[N];
int n, idx[N];
int f[N], hash[N];
int maxz = 0;
int c[N];

bool cmpx(int i, int j) { return a[i].x < a[j].x; }
bool cmpy(int i, int j) { return a[i].y < a[j].y; }
bool cmpz(int i, int j) { return a[i].z < a[j].z; }

void change(int a, int x)
{
	for(; a <= maxz; a += lowbit(a))
		c[a] = std::max(c[a], x);
}
int query(int b)
{
	int res = 0;
	for(; b > 0; b -= lowbit(b))
		res = std::max(res, c[b]);
	return res;
}

void solve(int l, int r)
{
	int m = (l + r) >> 1;
	std::sort(&idx[l], &idx[m]+1, cmpy);
	std::sort(&idx[m+1], &idx[r]+1, cmpy);
	int j = l;
	for(int i = m + 1; i <= r; i++)
	{
		for( ; j <= m && a[idx[j]].y < a[idx[i]].y; j++)
			change(a[idx[j]].z, f[a[idx[j]].x]);
		int tmp = query(a[idx[i]].z-1) + 1;
		if(tmp > f[a[idx[i]].x]) f[a[idx[i]].x] = tmp;
	}
	for(int j = l; j <= m; j++)
	{
		int i = a[idx[j]].z;
		for(; i <= maxz; i += lowbit(i))
			c[i] = 0;
	}
	std::sort(&idx[m+1], &idx[r]+1, cmpx);
}

void CDQ(int l, int r)
{
	if(l == r) return;
	int m = (l + r) >> 1;
	CDQ(l, m);
	solve(l, r);
	CDQ(m+1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].y, &a[i].z);
		a[i].x = i; idx[i] = i;
		f[i] = 1;
	}
	maxz = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[idx[i]].x != a[idx[i-1]].x) hash[idx[i]] = ++maxz;
		else hash[idx[i]] = maxz;
	}
	for(int i = 1; i <= n; i++) a[idx[i]].x = hash[idx[i]];
	std::sort(idx+1, idx+1+n, cmpy);
	maxz = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[idx[i]].y != a[idx[i-1]].y) hash[idx[i]] = ++maxz;
		else hash[idx[i]] = maxz;
	}
	for(int i = 1; i <= n; i++) a[idx[i]].y = hash[idx[i]];
	std::sort(idx+1, idx+1+n, cmpz);
	maxz = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[idx[i]].z != a[idx[i-1]].z) hash[idx[i]] = ++maxz;
		else hash[idx[i]] = maxz;
	}
	for(int i = 1; i <= n; i++) a[idx[i]].z = hash[idx[i]];
	std::sort(idx+1, idx+1+n, cmpx);
	CDQ(1, n);
	int res = 1;
	for(int i = 1; i <= n; i++)
		if(f[i] > res) res = f[i];
	printf("%d\n", res);
	return 0;
}
