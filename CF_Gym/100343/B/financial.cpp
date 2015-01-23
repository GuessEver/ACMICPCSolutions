#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;

const int N = 100000 + 10;

int n;
int K, ans[N];
struct Node{
	int real, num, o;
}a[N];
int head[N], tail[N];
int f[N], pre[N];
int tree[N*4];

bool cmpreal(Node _a, Node _b) { return _a.real < _b.real; }
bool cmp_o(Node _a, Node _b) { return _a.o < _b.o; }

void in_tree(int p, int l, int r, int k)
{
	if(l == r && l == a[k].num)
	{
		tree[p] = k;
		return;
	}
	int m = (l + r) / 2;
	if(a[k].num <= m) in_tree(p*2, l, m, k);
	else in_tree(p*2+1, m+1, r, k);
	if(f[tree[p*2]] > f[tree[p*2+1]]) tree[p] = tree[p*2];
	else tree[p] = tree[p*2+1];
}

int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return tree[p];
	int m = (l + r) / 2, x1 = 0, x2 = 0;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	if(f[x1] > f[x2]) return x1;
	else return x2;
}

int getpre(int zybcml)
{
	int low = 1, high = zybcml-1, res = 0;
	if(low > high) return 0;
	if(low == high)
	{
		if(a[zybcml].real - a[low].real >= K) return low;
		else return 0;
	}
	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(a[zybcml].real - a[mid].real >= K) low = mid+1, res = mid;
		else high = mid-1;
	}
	if(a[zybcml].real - a[res].real >= K) return res;
	else return 0;
}
int getaft(int zybcml)
{
	int low = zybcml+1, high = n;
	if(low > high) return n+1;
	if(low == high)
	{
		if(a[high].real - a[zybcml].real >= K) return high;
		else return n + 1;
	}
	while(low < high)
	{
		int mid = (low + high) / 2;
		if(a[mid].real - a[zybcml].real >= K) high = mid;
		else low = mid + 1;
	}
	if(a[high].real - a[zybcml].real >= K) return high;
	else return n + 1;
}

int main()
{
	freopen("financial.in", "r", stdin);
	freopen("financial.out", "w", stdout);
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].real);
		a[i].o = i;
	}
	sort(a+1, a+1+n, cmpreal);
/*	a[1].num = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i].real >= a[i-1].real + k) a[i].num = a[i-1].num + k;
		else if(a[i].real <= a[i-1].real - k) a[i].num = a[i-1].num - k;
		else a[i].num = a[i-1].num + (a[i].real - a[i-1].real);
	}*/
	for(int i = 1; i <= n; i++)
		a[i].num = (a[i].real == a[i-1].real) ? a[i-1].num : i;
	a[n+1].num = n+1;
	//for(int i = 1; i <= n; i++) printf("%d\t", a[i].real); puts("");
	//for(int i = 1; i <= n; i++) printf("%d\t", a[i].num); puts("");
	//puts("=========================");
	for(int i = 1; i <= n; i++)
	{
		head[a[i].num] = a[getpre(i)].num;
		tail[a[i].num] = a[getaft(i)].num;
	}
	//k = 1;
	sort(a+1, a+1+n, cmp_o);
	//for(int i = 1; i <= n; i++) printf("%d\t", a[i].real); puts("");
	//for(int i = 1; i <= n; i++) printf("%d\t", a[i].num); puts("");
	//for(int i = 1; i <= n; i++) printf("%d\t", head[a[i].num]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d\t", tail[a[i].num]); puts("");
	memset(f, 0, sizeof(f));
	memset(pre, 0, sizeof(pre));
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1;
		int k1 = 0, k2 = 0;
		if(head[a[i].num] >= 1) k1 = query(1, 1, n, 1, head[a[i].num]);
		if(tail[a[i].num] <= n) k2 = query(1, 1, n, tail[a[i].num], n);
		//printf("k1 = %d, k2 = %d\n", k1, k2);
		f[i] = std::max(f[k1], f[k2]) + 1;
		if(f[k1] > f[k2]) pre[i] = k1; else pre[i] = k2;
		in_tree(1, 1, n, i);
		//for(int i = 1; i <= 15; i++) printf("%d ", tree[i]); puts("");
	}
	//puts("<---------------------------------->");
	//for(int i = 1; i <= n; i++) printf("%d\t", f[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d\t", pre[i]); puts("");
	int k = -1;
	for(int i = 1; i <= n; i++)
		if(k == -1 || f[i] > f[k]) k = i;
	printf("%d\n", f[k]);
	//printans(k);
	int Cnt = 0;
	for(int i = k; i; i = pre[i]) ans[Cnt++] = a[i].real;
	for(int i = Cnt-1; i > 0; i--) printf("%d ", ans[i]); printf("%d\n", ans[0]);
	return 0;
}
