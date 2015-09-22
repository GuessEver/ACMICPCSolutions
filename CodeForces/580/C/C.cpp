#include <cstdio>
#include <vector>
using std::vector;
const int N = 100000 + 10;
int n, m, a[N];
vector<int> v[N];
int dp[N], dp2[N];
bool flag[N];

void solve(int x, int father)
{
	if(a[father] && a[x]) dp[x] = dp[father] + 1;
	else dp[x] = a[x];
	flag[father] = 1;
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
	{
		if(*it == father) continue;
		solve(*it, x);
	}
}

void solve2(int x, int father)
{
	dp2[x] = std::max(dp2[father], std::max(dp[father], dp[x]));
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
	{
		if(*it == father) continue;
		solve2(*it, x);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i < n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	solve(1, 0);
	solve2(1, 0);
	int res = 0;
	//for(int i = 1; i <= n; i++) printf("%d ", dp[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d ", dp2[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d ", flag[i]); puts("");
	for(int i = 1; i <= n; i++) if(!flag[i] && dp2[i] <= m) res++;
	printf("%d\n", res);
	return 0;
}
