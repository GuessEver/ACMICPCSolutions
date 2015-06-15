#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;

const int N = 2000 + 10;

int n, m;
vector<int> v[N], ans;
int res[N];
int in[N];
bool done[N];
priority_queue<int> Q;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) v[i].clear();
		memset(in, 0, sizeof(in));
		memset(done, 0, sizeof(done));
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			v[y].push_back(x); in[x]++;
		}
		while(!Q.empty()) Q.pop();
		for(int i = 1; i <= n; i++) if(in[i] == 0)
		{
			Q.push(i);
			done[i] = 1;
		}
		ans.clear();
		while(!Q.empty())
		{
			int x = Q.top(); Q.pop();
			ans.push_back(x);
			for(vector<int>::iterator it = v[x].begin(); it < v[x].end(); it++)
			{
				in[*it]--;
				if(in[*it] == 0 && !done[*it])
				{
					done[*it] = 1;
					Q.push(*it);
				}
			}
		}
		if(ans.size() != n) puts("-1");
		else {
			int i = 1;
			for(vector<int>::iterator it = ans.end() - 1; it >= ans.begin(); it--, i++)
				res[*it] = i;
			for(int i = 1; i < n; i++) printf("%d ", res[i]);
			printf("%d\n", res[n]);
		}
	}
	return 0;
}
