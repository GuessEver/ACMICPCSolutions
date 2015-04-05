#include <cstdio>
#include <cmath>
#include <vector>
using std::vector;

const int N = 100000 + 10;

int n, m;
vector<int> cap[N];
int sum[N];

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
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			cap[x].push_back(y);
			cap[y].push_back(x);
		}
		int q; scanf("%d", &q);
		while(q--)
		{
			int op, x; scanf("%d%d", &op, &x);
			if(op == 0)
			{
				int y; scanf("%d", &y);
				for(vector<int>::iterator it = cap[x].begin(); it < cap[x].end(); it++)
					sum[*it] += y;
			}
			else{
				printf("%d\n", sum[x]);
			}
		}
	}
	return 0;
}
