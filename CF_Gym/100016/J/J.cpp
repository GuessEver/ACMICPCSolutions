#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using std::min;
using std::pair;
using std::make_pair;

const int N = 2011 + 10;

int n, m;
struct Node{
	char name[30];
	int dis;
	bool operator < (const Node &b) const
	{
		return dis < b.dis;
	}
}boy[N], girl[N];
int f[N][N], g[N][N];
typedef pair<int, int> pir;
pir pre[N][N];

int calc(int x, int y, int l, int r)
{
	int res = 0;
	for(int i = x; i <= y; i++)
		if(boy[i].dis > res) res = boy[i].dis;
	for(int j = l; j <= r; j++)
		if(girl[j].dis > res) res = girl[j].dis;
	return res;
}

void PRINT(int bx, int by, int gx, int gy)
{
	int cnt = by - bx + 1 + gy - gx + 1;
	for(int i = bx; i <= by; i++)
	{
		cnt--;
		printf("%s", boy[i].name);
		if(cnt == 0) puts(".");
		else if(cnt == 1) printf(" and ");
		else printf(", ");
	}
	for(int i = gx; i <= gy; i++)
	{
		cnt--;
		printf("%s", girl[i].name);
		if(cnt == 0) puts(".");
		else if(cnt == 1) printf(" and ");
		else printf(", ");
	}
}

void dfs(int x, int y)
{
	if(x == 0 && y == 0) return;
	dfs(pre[x][y].first, pre[x][y].second);
	//printf("%d %d\n", x, y);
	//printf(" = %d\n", g[x][y]);
	//printf(" ! %d %d\n", pre[x][y].first, pre[x][y].second);
	printf("Taxi %d: ", g[x][y]);
	PRINT(pre[x][y].first+1, x, pre[x][y].second+1, y);
}

int main()
{
	freopen("taxi.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s%d", boy[i].name, &boy[i].dis);
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
		scanf("%s%d", girl[i].name, &girl[i].dis);
	std::sort(boy+1, boy+1+n);
	std::sort(girl+1, girl+1+m);
	int Taxi = (n+m+3) / 4;
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
		{
			for(int B = 1; B <= 4; B++)
				for(int G = 0; G <= 4-B; G++)
					if(i-B >= 0 && j-G >= 0)
					{
						int w = calc(i-B+1, i, j-G+1, j);
						if(f[i][j] > f[i-B][j-G] + w)
						{
							f[i][j] = f[i-B][j-G] + w;
							g[i][j] = g[i-B][j-G] + 1;
							pre[i][j] = make_pair(i-B, j-G);
						}
					}
		}
	//for(int i = 1; i <= n; i++)
	//{
	//	for(int j = 1; j <= m; j++)
	//		printf("%d ", f[i][j]);
	//	puts("");
	//}
	printf("%d\n", f[n][m]);
	printf("%d\n", g[n][m]);
	dfs(n, m);
	return 0;
}
