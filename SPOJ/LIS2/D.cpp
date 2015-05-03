#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(_X) ((_X)&(-(_X)))
// SPOJ LIS2
const int N = 100000 + 10;

int n, f[N], idx[N], hash[N];
struct Node{
	int x, y, z;
	void Read(int i)
	{
		scanf("%d%d", &y, &z);
		x = i; f[i] = 1; idx[i] = i;
	}
}a[N];
int maxp;
int c[N]; // tree Array

bool cmpx(int i, int j) { return a[i].x < a[j].x; }
bool cmpy(int i, int j) { return a[i].y < a[j].y; }
bool cmpz(int i, int j) { return a[i].z < a[j].z; }

void discrete()
{
	std::sort(idx+1, idx+1+n, cmpy); maxp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[idx[i]].y != a[idx[i-1]].y) hash[idx[i]] = ++maxp;
		else hash[idx[i]] = maxp;
	}
	for(int i = 1; i <= n; i++) a[idx[i]].y = hash[idx[i]];
	std::sort(idx+1, idx+1+n, cmpz); maxp = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1 || a[idx[i]].z != a[idx[i-1]].z) hash[idx[i]] = ++maxp;
		else hash[idx[i]] = maxp;
	}
	for(int i = 1; i <= n; i++) a[idx[i]].z = hash[idx[i]];
}

void insert(int a, int x)
{
	for( ; a <= maxp; a += lowbit(a)) c[a] = std::max(c[a], x);
}
int query(int a) // [1, a]
{
	int res = 0;
	for( ; a > 0; a -= lowbit(a)) res = std::max(res, c[a]);
	return res;
}

void solve(int l, int mid, int r)
{
	std::sort(&idx[l], &idx[mid]+1, cmpy);
	std::sort(&idx[mid+1], &idx[r]+1, cmpy);
	// [l, mid] .. calculated ok
	// now calculating [mid+1, r]
	// f[i] = max{f[j]} + 1;
	int j = l;
	for(int i = mid + 1; i <= r; i++)
	{
		for( ; j <= mid && a[idx[j]].y < a[idx[i]].y; j++)
			insert(a[idx[j]].z, f[a[idx[j]].x]);
		int tmp = query(a[idx[i]].z - 1);
		if(tmp + 1 > f[a[idx[i]].x]) f[a[idx[i]].x] = tmp + 1;
	}
	//memset(c, 0, sizeof(c));
	for(int i = l; i <= mid; i++)
	{
		int b = a[idx[i]].z;
		for( ; b <= maxp; b += lowbit(b)) c[b] = 0;
	}
	std::sort(&idx[mid+1], &idx[r]+1, cmpx);
	// CDQ(mid+1, r) next, so sort back it
}

void CDQ(int l, int r)
{
	if(l == r) return;
	int mid = l + (r - l) / 2;
	CDQ(l, mid);
	solve(l, mid, r);
	CDQ(mid + 1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) a[i].Read(i);
	discrete();
	std::sort(idx+1, idx+1+n, cmpx);
	CDQ(1, n);
	int res = 1;
	//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
	for(int i = 1; i <= n; i++) if(f[i] > res) res = f[i];
	printf("%d\n", res);
	return 0;
}
