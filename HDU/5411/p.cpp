#include <cstdio>
#include <vector>
using std::vector;
const int N = 50 + 10;
const int mod = 2015;

vector<int> v[N];
int n, m;
int res;
int ans[N];

void dfs(int x, int deep)
{
	if(deep > m) return;
	(res += 1) %= mod;
	(ans[deep] += 1) %= mod;
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
		dfs(*it, deep + 1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			v[i].clear();
			int k; scanf("%d", &k);
			while(k--)
			{
				int x; scanf("%d", &x);
				v[i].push_back(x);
			}
		}
		res = 1;
		for(int i = 1; i <= n; i++) dfs(i, 1);
		printf("%d\n", res);
		for(int i = 1; i <= m; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}
