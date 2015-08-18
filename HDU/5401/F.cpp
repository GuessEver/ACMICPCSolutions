#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
using std::pair;
using std::map;
const int M = 60 + 10;
const int mod = 1000000000 + 7;
int m;
long long a[M], b[M], c[M], d[M], l[M];
long long answer[M];
struct Tree{
	long long left, right, size;
}dis[M];
map<pair<long long, long long>, long long> len[M];

long long get(int p, long long x, long long y)
{
	if(p == 0 || x == y) return 0;
	if(x > y) std::swap(x, y);
	if(len[p].find(std::make_pair(x, y)) != len[p].end())
		return len[p][std::make_pair(x, y)];
	long long res = 0;
	if(x >= dis[a[p]].size) // x & y both in b[p]
		res = get(b[p], x - dis[a[p]].size, y - dis[a[p]].size);
	else if(y < dis[a[p]].size) // x & y both in a[p]
		res = get(a[p], x, y);
	else { // x in a[p] & y in b[p]
		res = l[p];
		(res += get(a[p], x, c[p])) %= mod;
		(res += get(b[p], y - dis[a[p]].size, d[p])) %= mod;
	}
	return len[p][std::make_pair(x, y)] = res;
}

void solve(int p, long long x, long long &D)
{
	if(p == 0) return;
	if(x >= dis[a[p]].size)
	{
		long long res = get(p, c[p], x);
		(D += dis[p].left) %= mod;
		(D += dis[a[p]].size % mod * res % mod) %= mod;
		solve(b[p], x - dis[a[p]].size, D);
	}
	else {
		long long res = get(p, x, d[p] + dis[a[p]].size);
		(D += dis[p].right) %= mod;
		(D += dis[b[p]].size % mod * res % mod) %= mod;
		solve(a[p], x, D);
	}
}

int main()
{
	while(scanf("%d", &m) == 1)
	{
		memset(dis, 0, sizeof(dis));
		dis[0].size = 1;
		for(int i = 1; i <= m; i++)
		{
			len[i].clear();
			scanf("%lld%lld%lld%lld%lld", &a[i], &b[i], &c[i], &d[i], &l[i]);
			answer[i] = (answer[a[i]] + answer[b[i]]) % mod;
			(answer[i] += dis[a[i]].size % mod * (dis[b[i]].size % mod) % mod * l[i] % mod) %= mod;
			solve(a[i], c[i], dis[i].left);
			solve(b[i], d[i], dis[i].right);
			dis[i].size = dis[a[i]].size + dis[b[i]].size;
			(answer[i] += (dis[b[i]].size % mod * dis[i].left % mod + dis[a[i]].size % mod * dis[i].right % mod) % mod) %= mod;
			printf("%lld\n", answer[i]);
			//printf("left = %lld, right = %lld, size = %lld\n", dis[i].left, dis[i].right, dis[i].size);
		}
	}
	return 0;
}
