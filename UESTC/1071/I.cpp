#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 2 * 100000 + 10;
const int inf = 0x3f3f3f3f;

int W, H, n, m;
struct Chess{
	int x, y;
	void Read() { scanf("%d%d", &x, &y); }
}chess[N];
struct Box{
	int x1, x2, y1, y2, idx;
	void Read(int i)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		idx = i;
	}
}box[N];

bool cmp_box_x(Box a, Box b) { return a.x2 < b.x2; }
bool cmp_box_y(Box a, Box b) { return a.y2 < b.y2; }
bool cmp_chess_x(Chess a, Chess b) { return a.x < b.x; }
bool cmp_chess_y(Chess a, Chess b) { return a.y < b.y; }

bool ok[N];
int val_min[N * 4];

void change(int p, int l, int r, int a, int c)
{
	if(l == r && l == a)
	{
		val_min[p] = c;
		return;
	}
	int mid = l + (r - l) / 2;
	if(a <= mid) change(p*2, l, mid, a, c);
	else change(p*2+1, mid+1, r, a, c);
	val_min[p] = std::min(val_min[p*2], val_min[p*2+1]);
}
int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return val_min[p];
	int mid = l + (r - l) / 2, x1 = inf, x2 = inf;
	if(a <= mid) x1 = query(p*2, l, mid, a, b);
	if(b > mid) x2 = query(p*2+1, mid+1, r, a, b);
	return std::min(x1, x2);
}

int main()
{
	scanf("%d%d%d%d", &W, &H, &n, &m);
	W = H = 100000;
	for(int i = 1; i <= n; i++) chess[i].Read();
	for(int i = 1; i <= m; i++) box[i].Read(i);
	int nowx = 0, nowy = 0;
	std::sort(chess+1, chess+1+n, cmp_chess_x);
	std::sort(box+1, box+1+m, cmp_box_x);
	int chess_head = 1, box_head = 1;
	memset(val_min, 0, sizeof(val_min));
	while(chess_head <= n)
	{
		nowx = chess[chess_head].x;
		while(chess_head <= n && chess[chess_head].x == nowx)
		{
			change(1, 1, H, chess[chess_head].y, nowx);
			chess_head++;
		}
		while(box_head <= m && ((chess_head <= n && box[box_head].x2 >= nowx && box[box_head].x2 < chess[chess_head].x) || (chess_head == n + 1 && box[box_head].x2 >= chess[n].x)))
		{
			int xMin = query(1, 1, H, box[box_head].y1, box[box_head].y2);
			ok[box[box_head].idx] |= (xMin >= box[box_head].x1);
			box_head++;
		}
	}
	//for(int i = 1; i <= m; i++) printf("%s\n", ok[i] ? "YES" : "NO");
	//memset(ok, 0, sizeof(ok));
	std::sort(chess+1, chess+1+n, cmp_chess_y);
	std::sort(box+1, box+1+m, cmp_box_y);
	chess_head = box_head = 1;
	memset(val_min, 0, sizeof(val_min));
	while(chess_head <= n)
	{
		nowy = chess[chess_head].y;
		while(chess_head <= n && chess[chess_head].y == nowy)
		{
			change(1, 1, W, chess[chess_head].x, nowy);
			chess_head++;
		}
		while(box_head <= m && ((chess_head <= n && box[box_head].y2 >= nowy && box[box_head].y2 < chess[chess_head].y) || (chess_head == n + 1 && box[box_head].y2 >= chess[n].y)))
		{
			int yMin = query(1, 1, W, box[box_head].x1, box[box_head].x2);
			ok[box[box_head].idx] |= (yMin >= box[box_head].y1);
			box_head++;
		}
	}
	for(int i = 1; i <= m; i++) printf("%s\n", ok[i] ? "YES" : "NO");
	return 0;
}
