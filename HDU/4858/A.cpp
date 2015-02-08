#include <cstdio>
#include <cmath>
#include <vector>
using std::vector;

const int N = 100000 + 10;

int n, m, Std, q;
int val[N], sum[N], deg[N];
vector<int> cap[N], S[N];
vector<int>::iterator it;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		Std = (int)sqrt(n);
		for(int i = 1; i <= n; i++)
		{
			S[i].clear();
			cap[i].clear();
			sum[i] = val[i] = deg[i] = 0;
		}
		int op, x, y, z;
		for(int i = 1; i <=m; i++)
		{
			scanf("%d%d", &x, &y);
			cap[x].push_back(y);
			cap[y].push_back(x);
			deg[x]++; deg[y]++;
		}
		for(int i = 1; i <= n; i++)
			for(it = cap[i].begin(); it < cap[i].end(); it++)
				if(deg[*it] > Std) S[i].push_back(*it);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &op, &x);
			if(op == 0)
			{
				scanf("%d", &z);
				if(deg[x] <= Std)
				{
					for(it = cap[x].begin(); it < cap[x].end(); it++)
						sum[*it] += z;
				}
				else val[x] += z;
			}
			else{
				int res = 0;
				for(it = S[x].begin(); it < S[x].end(); it++)
					res += val[*it];
				printf("%d\n", res + sum[x]);
			}
		}
	}
	return 0;
}
