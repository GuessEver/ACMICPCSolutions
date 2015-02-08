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
int len[8*N][12];

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

void init(int p, int l, int r)
{
	len[p][0] = P[r] - P[l];
	if(r - l == 1) return;
	int m = (l + r) / 2;
	init(p*2, l, m); init(p*2+1, m, r);
}

void solve(int p, int l, int r)
{
	memset(len[p], 0, sizeof(len[p]));
	if(r - l == 1)
	{
		int idx = std::min(K, cnt[p]);
		len[p][idx] = P[r] - P[l];
	}
	else{
		for(int k = 0; k <= K; k++)
		{
			int idx = std::min(K, cnt[p] + k);
			len[p][idx] += len[p*2][k] + len[p*2+1][k];
		}
	}
}

void update(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		cnt[p] += c;
		solve(p, l, r);
		return;
	}
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
		memset(len, 0, sizeof(len));
		memset(cnt, 0, sizeof(cnt));
		init(1, 1, maxy);
		long long res = 0;
		leny = 0;
		for(int i = 1; i <= n; i++)
		{
			res += 1ll * (l[i].x - l[i-1].x) * len[1][K];
			update(1, 1, maxy, l[i].down, l[i].up, l[i].sign);
			//for(int i = 1; i <= 8; i++) printf("%d : %d %d %d\n", i, cnt[i], len[i][0], len[i][1]);
			//puts("=========");
		}
		printf("Case %d: %lld\n", cas, res);
	}
	return 0;
}
