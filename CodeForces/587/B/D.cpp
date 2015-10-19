#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
using std::map;
const int N = 1000000 + 10;
const int mod = 1000000000 + 7;
int n, k;
long long part;
long long l;
int a[N];
int way[N], b[N];
map<int, int> rank;
int R, cnt[N];

int main()
{
	std::cin >> n >> l >> k;
	part = (l + n - 1) / n;
	k = std::min(0ll + k, part);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	std::sort(b, b + n);
	for(int i = 0; i < n; i++) if(i == 0 || b[i] != b[i-1]) rank[b[i]] = R++;
	int res = 0;
	for(int i = 1; i <= k; i++)
	{
		if(i == 1) for(int j = 0; j < n; j++) way[j] = 1;
		else for(int j = 0; j < n; j++) way[j] = cnt[rank[a[j]]];
		int sum = 0;
		for(int j = 0; j < n; j++) (sum += way[j]) %= mod;
		(res += (1ll * sum  * ((part - i + 1 - 1) % mod) % mod)) %= mod;
		int ed = l % n; if(ed == 0) ed = n;
		for(int j = 0; j < ed; j++) (res += way[j]) %= mod;
		for(int j = 0; j < n; j++) cnt[j] = 0;
		for(int j = 0; j < n; j++) (cnt[rank[a[j]]] += way[j]) %= mod;
		for(int j = 1; j < R; j++) (cnt[j] += cnt[j-1]) %= mod;
		//printf("%d %d\n", i, res);
	}
	printf("%d\n", res);
	return 0;
}
