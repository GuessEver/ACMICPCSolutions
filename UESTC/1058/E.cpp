#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

const int N = 100000 + 10;

int W, H, n, m;
struct Edge{
	int x1, x2, y, sign;
	bool operator < (const Edge &b) const
	{
		if(y == b.y) return x1 < b.x1;
		return y < b.y;
	}
}edge1[N * 2], edge2[N * 2];
int num1, num2;
int val[N * 4], len[N * 4];

int nextInt()
{
	char ch; int res = 0;
	while(!isdigit((ch = getchar()))) ;
	do res = (res << 3) + (res << 1) + ch - '0';
	while(isdigit((ch = getchar())));
	return res;
}

void update(int p, int l, int r)
{
	if(val[p] == 0)
	{
		if(l + 1 == r) len[p] = 0;
		else len[p] = len[p*2] + len[p*2+1];
	}
	else len[p] = r - l;
}

void insert(int p, int l, int r, int a, int b, int c)
{
	if(a <= l && b >= r)
	{
		val[p] += c;
		update(p, l, r);
		return;
	}
	int mid = (l + r) / 2;
	if(a < mid) insert(p*2, l, mid, a, b, c);
	if(b > mid) insert(p*2+1, mid, r, a, b, c);
	update(p, l, r);
}

long long solve(Edge *edge, int num, int MAX, int MAXY)
{
	MAX = std::max(1, MAX - (m - 1));
	//val[1] = 0; len[1] = 0;
	memset(val, 0, sizeof(val));
	memset(len, 0, sizeof(len));
	std::sort(edge+1, edge+num+1);
	long long res = 0;
	for(int i = 1; i <= num; i++)
	{
		int leny = edge[i+1].y - edge[i].y;
		//printf("[nowx: %d ~ %d] [nowy = %d] [%s] : leny = %d\n", edge[i].x1, edge[i].x2, edge[i].y, edge[i].sign == 1 ? "+" : "-", leny);
		insert(1, 1, MAX, edge[i].x1, std::min(MAX, edge[i].x2), edge[i].sign);
		if(i < num) res += 1ll * leny * len[1];
		//printf("covered = %d, sol-res = %lld\n", len[1], res);
	}
	return 1ll * (MAX - 1) * (MAXY - 1) - res;
}

int main()
{
	//scanf("%d%d%d%d", &W, &H, &n, &m);
	W = nextInt(); H = nextInt();
	n = nextInt(); m = nextInt();
	W++; H++;
	for(int i = 1; i <= n; i++)
	{
		int x1, x2, y1, y2;
		//scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 = nextInt(); y1 = nextInt();
		x2 = nextInt(); y2 = nextInt();
		x2++; y2++;
		edge1[++num1] = (Edge){std::max(1, x1-m+1), x2, y1, 1};
		edge1[++num1] = (Edge){std::max(1, x1-m+1), x2, y2, -1};
		edge2[++num2] = (Edge){std::max(1, y1-m+1), y2, x1, 1};
		edge2[++num2] = (Edge){std::max(1, y1-m+1), y2, x2, -1};
	}
	long long res = 0;
	res += solve(edge1, num1, W, H);
	if(m > 1) res += solve(edge2, num2, H, W);
	printf("%lld\n", res);
	return 0;
}
