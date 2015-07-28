#include <cstdio>
#include <cstring>
#include <vector>
using std::vector;

const int N = 100 + 10;
vector<int> cap[N];
bool notroot[N];
int size[N];
int n, k;

int dfs(int x)
{
	size[x] = 1;
	for(vector<int>::iterator it = cap[x].begin(); it != cap[x].end(); it++)
		size[x] += dfs(*it);
	return size[x];
}

int main()
{
	while(scanf("%d%d", &n, &k) == 2)
	{
		for(int i = 1; i <= n; i++) cap[i].clear();
		memset(notroot, 0, sizeof(notroot));
		memset(size, 0, sizeof(size));
		for(int i = 1; i < n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[x].push_back(y);
			notroot[y] = 1;
		}
		for(int i = 1; i <= n; i++) if(!notroot[i])
			dfs(i);
		int cnt = 0;
		for(int i = 1; i <= n; i++) if(size[i] - 1 == k) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}
