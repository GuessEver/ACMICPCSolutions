#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;
#define sqr(_X) ((_X)*(_X))

const int N = 30 + 10;

int n, maxscore;
double f[N][N*210];
struct Point{
	int x, y, s;
	void Read() 
	{
		scanf("%d%d%d", &x, &y, &s);
		maxscore += s;
	}
}a[N];
struct People{
	char name[100]; int tot;
	bool Read()
	{
		scanf("%s%d", name, &tot);
		if(!strcmp(name, "#") && tot == 0) return 0;
		return 1;
	}
};
vector<People> p;
vector<People>::iterator it;

double DIS(int i, int j)
{
	return sqrt(sqr(1.0 * a[i].x - a[j].x) + sqr(1.0 * a[i].y - a[j].y));
}

void solve()
{
	for(int i = 0; i <= n+1; i++)
		for(int j = 0; j <= maxscore; j++)
			f[i][j] = 1e20;
	f[0][0] = 0;
	for(int i = 1; i <= n+1; i++)
		for(int k = 0; k < i; k++)
				for(int j = maxscore; j >= a[i].s; j--)
				f[i][j] = std::min(f[i][j], f[k][j-a[i].s] + DIS(i, k));
	/*
	for(int i = 0; i <= n; i++)
		for(int k = i+1; k <= n+1; k++)
			for(int j = 0; j <= maxscore - a[k].s; j++)
				f[k][j+a[k].s] = std::min(f[k][j+a[k].s], f[i][j] + DIS(i, k));
	*/
}

int main()
{
	freopen("F.in", "r", stdin);
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		maxscore = 0;
		for(int i = 1; i <= n; i++) a[i].Read();
		a[n+1] = a[0];
		People tmp; p.clear();
		while(tmp.Read()) p.push_back(tmp);
		solve();
		printf("Race %d\n", ++cas);
		for(it = p.begin(); it < p.end(); it++)
		{
			for(int j = maxscore; j >= 0; j--)
				if(f[n+1][j] <= 1.0 * it -> tot + 1e-7)
				{
					printf("%s: %d\n", it -> name, j);
					break;
				}
		}
	}
	return 0;
}
