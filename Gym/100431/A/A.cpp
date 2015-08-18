#include <cstdio>
#include <vector>
using std::vector;
const int N = 1000 + 10;

int n, m;
vector<int> v[N];
bool vis[N][N];
int color[N], cnt;

void euler(int x)
{
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
		if(!vis[x][*it])
		{
			vis[x][*it] = vis[*it][x] = 1;
			euler(*it);
			//printf("%d -> ", *it);
			color[++cnt] = *it;
		}
}

int main()
{
	//freopen("achromatic.in", "r", stdin);
	//freopen("achromatic.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; ; i++)
	{
		int tmp;
		if(i % 2) tmp = i * (i - 1) / 2;
		else tmp = i * (i - 2) / 2 + i;
		if(tmp <= n) m = i; else break;
	}
	if(m % 2 == 1 && m * (m - 1) / 2 + 1 == n) m--;
	if(m % 2)
	{
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
			{
				if(i == j) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		euler(1); color[++cnt] = 1;
	}
	else {
		for(int i = 1; i <= m; i++)
			for(int j = 1; j <= m; j++)
			{
				if(i == j) continue;
				if(i == j + m / 2) continue;
				if(i + m / 2 == j) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		euler(1); color[++cnt] = 1;
		for(int i = 1, j = 0; j < m / 2; j++)
		{
			i += m / 2; if(i > m) i -= m;
			color[++cnt] = i;
			i += 1; if(i > m) i -= m;
			color[++cnt] = i;
		} cnt--;
	}
	if(cnt < n)
	{
		for(int i = cnt + 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				if(j == color[i - 1]) continue;
				if(i == n && j == color[1]) continue;
				color[i] = j;
				break;
			}
	}
	printf("%d\n", m);
	for(int i = 1; i <= n; i++)
		printf("%d%s", color[i], i == n ? "\n" : " ");
	return 0;
}
