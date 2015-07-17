#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 100000 + 10;

int n;
vector<int> vx[N], vy[N];
vector<int>::iterator it, jt;
struct Point{int x, y;}p[N];

bool cmpx(const Point &a, const Point &b) { return a.x < b.x; }
bool cmpy(const Point &a, const Point &b) { return a.y < b.y; }

int count(vector<int> &v, int m)
{
	it = std::lower_bound(v.begin(), v.end(), m);
	//printf("%d\n", (int)(it-v.begin()));
	return (int)(it-v.begin());
}

int solve()
{
	int res = 0;
	for(int i = 1; i <= n; i++) // left down point
	{
		int x = p[i].x, y = p[i].y;
		//printf("%d %d\n", x, y);
		int row = vy[y].size() - count(vy[y], x) - 1;
		int col = vx[x].size() - count(vx[x], y) - 1;
		//printf("row = %d, colum = %d\n", row, col);
		if(!row || !col) continue; // not enough
		if(row < col)
		{
			it = std::lower_bound(vy[y].begin(), vy[y].end(), x);
			for(it++; it < vy[y].end(); it++)
			{
				int len = *it - x;
				jt = std::lower_bound(vx[x].begin(), vx[x].end(), y + len);
				if(jt == vx[x].end() || *jt != y + len) continue;
				jt = std::lower_bound(vx[*it].begin(), vx[*it].end(), y + len);
				if(jt == vx[*it].end() || *jt != y + len) continue;
				res++;
			}
		}
		else {
			it = std::lower_bound(vx[x].begin(), vx[x].end(), y);
			for(it++; it < vx[x].end(); it++)
			{
				int len = *it - y;
				jt = std::lower_bound(vy[y].begin(), vy[y].end(), x + len);
				if(jt == vy[y].end() || *jt != x + len) continue;
				jt = std::lower_bound(vy[*it].begin(), vy[*it].end(), x + len);
				if(jt == vy[*it].end() || *jt != x + len) continue;
				res++;
			}
		}
	}
	return res;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
		std::sort(p+1, p+1+n, cmpx);
		for(int i = 1; i <= n; i++)
			vy[p[i].y].push_back(p[i].x);
		std::sort(p+1, p+1+n, cmpy);
		for(int i = 1; i <= n; i++)
			vx[p[i].x].push_back(p[i].y);
		printf("%d\n", solve());
		memset(vx, 0, sizeof(vx));
		memset(vy, 0, sizeof(vy));
	}
	return 0;
}
