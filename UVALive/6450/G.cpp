#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

int n, cap[50][50];
int tot;
int a[50];
bool quit;

void dfs(int x, int S, int steps)
{
	if(quit) return;
	if(x > n)
	{
		if(S == tot-1)
		{
			printf("%d\n", steps);
			quit = 1;
		}
		return;
	}
	dfs(x+1, S, steps);
	int status = 0;
	for(int j = 1; j <= n; j++) if(cap[x][j])
		status |= (1 << (j-1));
	status |= (1 << (x-1));
	bool add = ((S | status) != S);
	dfs(x+1, S|status, steps+add);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		tot = 1 << n;
		memset(cap, 0, sizeof(cap));
		for(int i = 1; i <= n; i++)
		{
			int d; scanf("%d", &d);
			while(d--)
			{
				int j; scanf("%d", &j);
				cap[i][j] = cap[j][i] = 1;
			}
		}
		quit = 0;
		dfs(1, 0, 0);
		//if(!quit) printf("%d\n", n);
	}
	return 0;
}
