#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using std::map;

const int N = 30000 + 10;

int n, K;
struct Line{
	int x, down, up, sign;
	Line() {}
	Line(int a, int b, int c, int d)
		{ x = a; down = b; up = c; sign = d; }
	bool operator < (const Line &b) const
		{ return x < b.x; }
}l[2*N];
int cor[2*N], P[2*N], maxy, leny;
map<int, int> hash;
int cnt[8*N];
int len[8*N][11];

void Read()
{
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x2++; y2++;
		l[2*i-1] = Line(x1, y1, y2, 1);
		l[2*i] = Line(x2, y1, y2, -1);
		cor[2*i-1] = y1;
		cor[2*i] = y2;
	}
	n *= 2;
	std::sort(cor+1, cor+1+n);
	maxy = 0; hash.clear();
	for(int i = 1; i <= n; i++)
		if(!hash[cor[i]])
		{
			hash[cor[i]] = ++maxy;
			P[maxy] = cor[i];
		}
	for(int i = 1; i <= n; i++)
	{
		l[i].up = hash[l[i].up];
		l[i].down = hash[l[i].down];
	}
	std::sort(l+1, l+1+n);
}

void solve(int p, int l, int r)
{
}

void update(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		cnt[p] += c;
		solve(p, l, r);
	}
	if(r - l == 1) return;
	int m = (l + r) / 2;
	if(a < m) update(p*2, l, m, a, b, c);
	if(b > m) update(p*2+1, m, r, a, b, c);
	solve(p, l, r);
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		Read();
		cnt[1] = 0;
		long long res = 0;
		leny = 0;
		for(int i = 1; i <= n; i++)
		{
			res += 1ll * (l[i].x - l[i-1].x) * len[1][K];
			update(1, 1, maxy, l[i].down, l[i].up, l[i].sign);
		}
		printf("Case %d: %lld\n", cas, res);
	}
	return 0;
}
