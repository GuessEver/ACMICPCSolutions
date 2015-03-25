#include <cstdio>
#include <algorithm>

const int N = 10000 + 10;

int n, m;
int val[4*N], sum[4*N];
long long dis[32][N*110];
struct Circle{
	int x, y, r;
	void Read() { scanf("%d%d%d", &x, &y, &r); }
}cir[N];
struct Point{
	int x, y;
	void Read() { scanf("%d%d", &x, &y); }
}point[110];

long long DIS(int x1, int y1, int x2, int y2)
{
	return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
}

void changeSum(int deep, int p, int l, int r, int c)
{
	int st = m * (l - 1), ed = st + (r - l + 1) * m;// [st, ed)
	int k = std::lower_bound(dis[deep]+st, dis[deep]+ed, c*c) - dis[deep] - st;
	sum[p] = k;
}

void init(int p, int l, int r, int deep)
{
	int st = m * (l - 1), ed = st + (r - l + 1) * m;// [st, ed)
	//printf("[%d,%d] deep = %d  start = %d end = %d\n", l, r, deep, st, ed);
	for(int i = st; i < ed; i++) dis[deep][i] = dis[0][i];
	std::sort(dis[deep]+st, dis[deep]+ed);
	if(l == r)
	{
		val[p] = cir[l].r;
		changeSum(deep, p, l, r, cir[l].r);
		return;
	}
	int mid = l + (r - l) / 2;
	init(p*2, l, mid, deep+1);
	init(p*2+1, mid+1, r, deep+1);
	val[p] = -1;
	sum[p] = sum[p*2] + sum[p*2+1];
}

void change(int p, int l, int r, int a, int b, int c, int deep)
{
	int st = m * (l - 1), ed = st + (r - l + 1) * m;// [st, ed)
	if(a <= l && b >= r)
	{
		val[p] = c;
		changeSum(deep, p, l, r, c);
		return;
	}
	int mid = l + (r - l) / 2;
	if(val[p] != -1)
	{
		val[p*2] = val[p*2+1] = val[p];
		val[p] = -1;
		changeSum(deep+1, p*2, l, mid, val[p*2]);
		changeSum(deep+1, p*2+1, mid+1, r, val[p*2+1]);
	}
	if(a <= mid) change(p*2, l, mid, a, b, c, deep+1);
	if(b > mid) change(p*2+1, mid+1, r, a, b, c, deep+1);
	if(val[p] == -1 && val[p*2] == val[p*2+1]) val[p] = val[p*2];
	sum[p] = sum[p*2] + sum[p*2+1];
}

int query(int p, int l, int r, int a, int b, int deep)
{
	if(a <= l && b >= r) return sum[p];
	int mid = l + (r - l) / 2, x1 = 0, x2 = 0;
	if(val[p] != -1)
	{
		val[p*2] = val[p*2+1] = val[p];
		val[p] = -1;
		changeSum(deep+1, p*2, l, mid, val[p*2]);
		changeSum(deep+1, p*2+1, mid+1, r, val[p*2+1]);
	}
	if(a <= mid) x1 = query(p*2, l, mid, a, b, deep+1);
	if(b > mid) x2 = query(p*2+1, mid+1, r, a, b, deep+1);
	//sum[p] = sum[p*2] + sum[p*2+1];
	return x1 + x2;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) cir[i].Read();
	for(int i = 1; i <= m; i++) point[i].Read();
	int idx = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dis[0][idx++] = DIS(cir[i].x, cir[i].y, point[j].x, point[j].y);
	init(1, 1, n, 1);
	/*for(int i = 1; i <= 3; i++)
	{
		for(int j = 0; j < n * m; j++) printf("%lld ", dis[i][j]);
		puts("");
	}*/
	int q; scanf("%d", &q);
	while(q--)
	{
		int op, x, y, r;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1)
		{
			scanf("%d", &r);
			change(1, 1, n, x, y, r, 1);
		}
		else{
			printf("%d\n", query(1, 1, n, x, y, 1));
		}
	}
	return 0;
}
