#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;

int n, m, row[N], col[N];

bool bigger(int a, int b) { return a > b; }

int solve()
{
	int subrow = 0;
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(row[i] == m)
		{
			subrow++;
			res += m;
			continue;
		}
		for(int j = 1; j <= row[i]; j++)
		{
			col[j]--;
			res++;
		}
		std::sort(col+1, col+1+m, bigger);
	}
	for(int j = 1; j <= m; j++)
		if(col[j] - subrow > 0)	
			res += col[j] - subrow;
	return res;
}

int main()
{
	//freopen("F.in", "r", stdin);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &row[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &col[i]);
		std::sort(row+1, row+1+n, bigger);
		std::sort(col+1, col+1+m, bigger);
		printf("%d\n", solve());
	}
	return 0;
}

