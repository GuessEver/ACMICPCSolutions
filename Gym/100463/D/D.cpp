#include <cstdio>

const int N = 20 + 10;
const int inf = 0x3f3f3f3f;

int n;
int answer, number_red;
struct Point{
	int x, y, blue;
	void Read()
	{
		scanf("%d%d%d", &x, &y, &blue);
		if(!blue) number_red++;
	}
	bool inRectangle(int minX, int maxX, int minY, int maxY)
	{
		return x >= minX && x <= maxX && y >= minY && y <= maxY;
	}
}p[N];
bool choose[N];

void dfs(int x)
{
	if(x > n)
	{
		int cnt = 0, maxX = -inf, maxY = -inf, minX = inf, minY = inf;
		for(int i = 1; i <= n; i++) if(choose[i])
		{
			if(p[i].blue) return;
			if(p[i].x > maxX) maxX = p[i].x;
			if(p[i].x < minX) minX = p[i].x;
			if(p[i].y > maxY) maxY = p[i].y;
			if(p[i].y < minY) minY = p[i].y;
		}
		for(int i = 1; i <= n; i++)
			if(p[i].inRectangle(minX, maxX, minY, maxY))
			{
				if(p[i].blue) return;
				cnt++;
			}
		if(cnt * 2 != number_red) return;
		int S = (maxY - minY) * (maxX - minX);
		if(answer == -1 || S < answer) answer = S;
		return;
	}
	choose[x] = 0;
	dfs(x+1);
	choose[x] = 1;
	dfs(x+1);
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		number_red = 0; answer = -1;
		for(int i = 1; i <= n; i++) p[i].Read();
		dfs(1);
		printf("Case %d: %d\n", ++cas, answer);
	}
	return 0;
}
