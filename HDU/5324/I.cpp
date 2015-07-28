#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using std::vector;
#define lowbit(_X) ((_X)&(-(_X)))
// SPOJ LIS2
const int N = 50000 + 10;

int n, f[N], idx[N], hash[N];
struct Node{
	int x, y, z;
}a[N];
int maxp;
struct TA{
	int c, i;
	bool operator < (const TA &b) const
	{
		if(c == b.c) return i < b.i;
		return c < b.c;
	}
	TA() {}
	TA(int a, int b) { c = a; i = b; }
}c[N]; // tree Array
int pre[N];
int answer = 0;

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

void insert(int a, TA x)
{
	for( ; a <= maxp; a += lowbit(a)) c[a] = std::max(c[a], x);
}
TA query(int a) // [1, a]
{
	TA res; res.c = res.i = 0;
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
		for( ; j <= mid && a[idx[j]].y <= a[idx[i]].y; j++)
			insert(a[idx[j]].z, TA(f[a[idx[j]].x], a[idx[j]].x));
		TA tmp = query(a[idx[i]].z);
		if(tmp.c + 1 > f[a[idx[i]].x] || (tmp.c + 1 == f[a[idx[i]].x] && tmp.i > pre[a[idx[i]].x]))
		{
			f[a[idx[i]].x] = tmp.c + 1;
			pre[a[idx[i]].x] = tmp.i;
		}
	}
	//memset(c, 0, sizeof(c));
	for(int i = l; i <= mid; i++)
	{
		int b = a[idx[i]].z;
		for( ; b <= maxp; b += lowbit(b)) c[b].c = c[b].i = 0;
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
vector<int> v1, v2;
void getMin()
{
	if((int)v1.size() == 0) v1 = v2;
	else {
		for(int i = 0; i < answer; i++)
			if(v2[i] < v1[i])
			{
				v1 = v2;
				return;
			}
	}
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].y);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].z);
		for(int i = 1; i <= n; i++)
		{
			a[i].z = -a[i].z;
			a[i].x = n - i + 1;
			f[i] = 1; idx[i]= i;
		}
		memset(pre, -1, sizeof(pre));
		discrete();
		std::sort(idx+1, idx+1+n, cmpx);
		//for(int i = 1; i <= n; i++) printf("%d %d %d\n", a[idx[i]].x, a[idx[i]].y, a[idx[i]].z);
		CDQ(1, n);
		//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
		answer = 0;
		for(int i = 1; i <= n; i++) answer = std::max(answer, f[i]);
		printf("%d\n", answer);
		v1.clear();
		for(int i = 1; i <= n; i++) if(f[i] == answer)
		{
			v2.clear();
			for(int S = i; S != -1; S = pre[S]) v2.push_back(n - S + 1);
			getMin();
		}
		for(int i = 0; i < answer; i++) printf("%d%s", v1[i], i == answer - 1 ? "\n" : " ");
	}
	return 0;
}
