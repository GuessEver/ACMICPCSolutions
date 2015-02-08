#include <cstdio>
#include <algorithm>
#include <set>
using std::multiset;
using std::lower_bound;

const int N = 100000 + 10;

struct Grass{
	int price, green;
	bool operator < (const Grass &b) const
	{
		return green > b.green;
	}
}cow[N], g[N];
int n, m;
multiset<int> l;

long long solve()
{
	int j = 1;
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		while(j <= m && g[j].green >= cow[i].green)
		{
			l.insert(g[j].price);
			j++;
		}
		multiset<int>::iterator it = l.lower_bound(cow[i].price);
		if(it == l.end()) return -1;
		res += *it;
		l.erase(it);
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d%d", &cow[i].price, &cow[i].green);
	for(int i = 1; i <= m; i++) scanf("%d%d", &g[i].price, &g[i].green);
	std::sort(cow+1, cow+1+n);
	std::sort(g+1, g+1+m);
	long long res = solve();
	printf("%lld\n", res);
	return 0;
}
