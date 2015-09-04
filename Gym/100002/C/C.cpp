#include <cstdio>
#include <algorithm>

int H, W, n;
struct Point{
	int x, y;
	void Read()
	{
		scanf("%d%d", &x, &y);
	}
}a[110];
int ans_x = -1, ans_y = -1, ans_len = -1;
int x[500], y[500], xlen, ylen;
bool hash_x[10010], hash_y[10010];

bool check(int x1, int y1, int len)
{
	int x2 = x1 + len, y2 = y1 + len;
	if(x2 > W || y2 > H) return 0;
	for(int i = 1; i <= n; i++)
		if(a[i].x > x1 && a[i].x < x2 && a[i].y > y1 && a[i].y < y2) return 0;
	return 1;
}

int main()
{
	freopen("cricket.in", "r", stdin);
	freopen("cricket.out", "w", stdout);
	scanf("%d%d%d", &n, &W, &H);
	for(int i = 1; i <= n; i++) a[i].Read();
	hash_x[0] = hash_x[W] = hash_y[0] = hash_y[H] = 1;
	x[++xlen] = 0; x[++xlen] = W;
	x[++ylen] = 0; y[++ylen] = H;
	for(int i = 1; i <= n; i++)
	{
		if(!hash_x[a[i].x])
		{
			hash_x[a[i].x] = 1;
			x[++xlen] = a[i].x;
		}
		if(!hash_y[a[i].y])
		{
			hash_y[a[i].y] = 1;
			y[++ylen] = a[i].y;
		}
	}
	for(int i = 1; i <= xlen; i++)
		for(int j = 1; j <= ylen; j++)
		{
			int low = 1, high = std::min(W, H), ans = 1;
			while(low <= high)
			{
				int mid = low + (high - low) / 2;
				if(check(x[i], y[j], mid)) { low = mid + 1; ans = mid; }
				else high = mid - 1;
			}
			if(ans > ans_len)
			{
				//printf("!! %d %d %d\n", ans, i, j);
				ans_len = ans;
				ans_x = x[i]; ans_y = y[j];
			}
		}
	printf("%d %d %d\n", ans_x, ans_y, ans_len);
	return 0;
}
