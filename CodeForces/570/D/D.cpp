#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
const int N = 500000 + 10;

int n, m;
vector<int> v[N], g[26][N];
int deep[N], in[N], ou[N], timeStamp;
char s[N];

void dfs(int x, int d)
{
	deep[x] = d; in[x] = ++timeStamp;
	for(vector<int>::iterator it = v[x].begin(); it != v[x].end(); it++)
		dfs(*it, d + 1);
	ou[x] = timeStamp;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++)
	{
		int x; scanf("%d", &x);
		v[x].push_back(i);
	}
	dfs(1, 1);
	//for(int i = 1; i <= n; i++) printf("%d ", deep[i]); puts("");
	//for(int i = 1; i <= n; i++) printf("%d %d\n", in[i], ou[i]);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		g[s[i]-'a'][deep[i]].push_back(in[i]);
	for(int i = 0; i < 26; i++)
		for(int j = 1; j <= n; j++)
			std::sort(g[i][j].begin(), g[i][j].end());
	while(m--)
	{
		int x, d; scanf("%d%d", &x, &d);
		int odd = 0;
		if(d > deep[x])
		for(int i = 0; i < 26; i++)
		{
			int tmp = std::upper_bound(g[i][d].begin(), g[i][d].end(), ou[x])
				- std::lower_bound(g[i][d].begin(), g[i][d].end(), in[x]);
			if(tmp % 2 == 1) odd++;
		}
		puts(odd <= 1 ? "Yes" : "No");
	}
	return 0;
}
