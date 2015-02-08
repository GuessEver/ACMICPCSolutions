#include <cstdio>
#include <vector>
using std::vector;

const int N = 100000 + 10;

int n, m, q, sum[N];
vector<int> cap[N];
vector<int>::iterator it;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			cap[i].clear();
			sum[i] = 0;
		}
		int op, x, y;
		for(int i = 1; i <=m; i++)
		{
			scanf("%d%d", &x, &y);
			cap[x].push_back(y);
			cap[y].push_back(x);
		}
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d%d", &op, &x);
			if(op == 0)
			{
				scanf("%d", &y);
				for(it = cap[x].begin(); it < cap[x].end(); it++)
					sum[*it] += y;
			}
			else{
				printf("%d\n", sum[x]);
			}
		}
	}
	return 0;
}
