#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using std::vector;
using std::map;

const int N = 30000 + 10;

int n, m, K;
struct Segment{
	int x, y1, y2, sign; // y1 < y2
	Segment() {}
	Segment(int a, int b, int c, int d)
		{ x = a; y1 = b; y2 = c; sign = d; }
	bool operator < (const Segment &b) const
		{ return x < b.x; }
}seg[N*2];
vector<int> coordinate;
map<int, int> hash;
int maxp, P[N*2];
int len[N*2*4][12], cover[N*2*4];

void init(int p, int l, int r)
{
	len[p][0] = P[r] - P[l];
	if(l + 1 == r) return;
	int mid = l + (r - l) / 2;
	init(p*2, l, mid); init(p*2+1, mid, r);
}

void update(int p, int l, int r)
{
	memset(len[p], 0, sizeof(len[p]));
	if(r - l == 1)
	{
		int cnt = std::min(K, cover[p]);
		len[p][cnt] = P[r] - P[l];
	}
	else {
		for(int k = 0; k <= K; k++)
		{
			int cnt = std::min(K, cover[p] + k);
			len[p][cnt] += len[p*2][k] + len[p*2+1][k];
		}
	}
}

void modify(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		cover[p] += c;
		update(p, l, r);
		return;
	}
	int mid = l + (r - l) / 2;
	if(a < mid) modify(p*2, l, mid, a, b, c);
	if(b > mid) modify(p*2+1, mid, r, a, b, c);
	update(p, l, r);
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d", &n, &K);
		m = maxp = 0; coordinate.clear(); hash.clear();
		for(int i = 1; i <= n; i++)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x2++; y2++;
			seg[++m] = Segment(x1, y1, y2, 1);
			seg[++m] = Segment(x2, y1, y2, -1);
			coordinate.push_back(y1);
			coordinate.push_back(y2);
		}
		std::sort(coordinate.begin(), coordinate.end());
		//for(vector<int>::iterator it = coordinate.begin(); it != coordinate.end(); it++) printf("%d ", *it); puts("");
		for(vector<int>::iterator it = coordinate.begin(); it != coordinate.end(); it++)
			if(hash.find(*it) == hash.end())
			{
				hash[*it] = ++maxp;
				P[maxp] = *it;
			}
		for(int i = 1; i <= m; i++)
		{
			seg[i].y1 = hash[seg[i].y1];
			seg[i].y2 = hash[seg[i].y2];
		}
		std::sort(seg+1, seg+1+m);
		//for(int i = 1; i <= m; i++) printf("%d: %d %d\n", seg[i].x, seg[i].y1, seg[i].y2);
		memset(len, 0, sizeof(len));
		memset(cover, 0, sizeof(cover));
		init(1, 1, maxp);
		long long res = 0;
		for(int i = 1; i <= m; i++)
		{
			//printf("Adding %d : %d ~ %d\n", seg[i].x, seg[i].y1, seg[i].y2);
			modify(1, 1, maxp, seg[i].y1, seg[i].y2, seg[i].sign);
			//printf("%d %d\n", len[1][0], len[1][1]);
			//for(int p = 1; p <= 8; p++) printf("len[%d][0] = %d, len[%d][1] = %d\n", p, len[p][0], p, len[p][1]);
			//puts("");
			if(i < m) res += 1ll * len[1][K] * (seg[i+1].x - seg[i].x);
		}
		printf("Case %d: %lld\n", cas, res);
	}
	return 0;
}
