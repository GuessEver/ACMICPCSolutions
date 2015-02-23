#include <cstdio>
#include <algorithm>
#include <map>
using std::map;

const int N = 20000 + 10;
/*
	sa[rank[i]] = i
	sa[i] = j		: rank i is s[j, n)
	rank[j] = i		: s[j, n) is rank i
	height[i] = j	: the longest common prefix of string rank _i and _i-1
*/

int sa[N], rank[N];
int c[N], tmp[N];
int height[N];

bool cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void DA(int *s, int n, int m) // s[0...n-1] E [1, m)
{
	int i, j, p, *x = rank, *y = tmp;
	for(i = 0; i < m; i++) c[i] = 0;
	for(i = 0; i < n; i++) c[x[i] = s[i]]++;
	for(i = 1; i < m; i++) c[i] += c[i-1];
	for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
	for(j = 1, p = 0; p < n; j *= 2, m = p)
	{
		for(p = 0, i = n-j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < m; i++) c[i] = 0;
		for(i = 0; i < n; i++) c[x[y[i]]]++;
		for(i = 1; i < m; i++) c[i] += c[i-1];
		for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		for(std::swap(x, y), p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p - 1 : p++;
	}
	for(i = 0; i < n; i++) rank[sa[i]] = i;

	int k = 0; height[0] = 0;
	for(i = 0; i < n; height[rank[i++]] = k) if(rank[i])
		for(k ? k-- : 0, j = sa[rank[i]-1]; s[j+k] == s[i+k]; k++);
}

int n, K, a[N];
map<int, int> hash;

bool check(int len)
{
	int cnt = 0;
	for(int i = 1; i < n; i++)
	{
		if(height[i] >= len) cnt++;
		else cnt = 0;
		if(cnt >= K - 1) return 1;
	}
	return 0;
}

int Solve()
{
	int low = 0, high = n, ans = 0;
	while(low <= high)
	{
		int mid = low + (high - low) / 2;
		if(check(mid)) { low = mid + 1; ans = mid; }
		else high = mid - 1;
	}
	return ans;
}

int main()
{
	//freopen("J.in", "r", stdin);
	scanf("%d%d", &n, &K);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		tmp[i] = a[i];
	}
	std::sort(tmp, tmp+n);
	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(i == 0 || tmp[i] != tmp[i-1]) hash[tmp[i]] = ++cnt;
	for(int i = 0; i < n; i++) a[i] = hash[a[i]];
	a[n++] = 0;
	DA(a, n, cnt+1);
/*	for(int i = 0; i < n; i++)
	{
		printf("rank = %d -> [%d, %d) [%d] :", i, sa[i], n, height[i]);
		for(int j = sa[i]; j < n; j++) printf(" %d", a[j]);
		puts("");
	}	*/
	printf("%d\n", Solve());
	return 0;
}
