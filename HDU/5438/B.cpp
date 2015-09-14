#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using std::vector;
using std::queue;
const int N = 10000 + 10;
int n, m, a[N], deg[N];
long long sum;
queue<int> Q;
bool done[N];
vector<int> v[N];

int dfs(int x, long long &sum)
{
	if(done[x]) return 0;
	done[x] = 1; sum += a[x];
	int cnt = 0;
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
		cnt += dfs(*it, sum);
	return cnt + 1;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m); sum = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			v[i].clear();
		}
		memset(deg, 0, sizeof(deg));
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
			++deg[x]; ++deg[y];
		}
		for(int i = 1; i <= n; i++) if(deg[i] < 2) Q.push(i);
		memset(done, 0, sizeof(done));
		while(!Q.empty())
		{
			int x = Q.front(); Q.pop();
			if(done[x]) continue;
			done[x] = 1;
			for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
				if(!done[*it])
				{
					--deg[x];
					--deg[*it];
					if(deg[*it] < 2) Q.push(*it);
				}
		}
		//for(int i = 1; i <= n; i++) if(!done[i]) printf("%d ", i); puts("");
		long long res = 0;
		for(int i = 1; i <= n; i++) if(!done[i])
		{
			long long tmpSum = 0;
			int tmp = dfs(i, tmpSum);
			if(tmp & 1) res += tmpSum;
		}
		printf("%lld\n", res);
	}
	return 0;
}
