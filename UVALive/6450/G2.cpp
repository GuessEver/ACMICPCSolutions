#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

int n, cap[50][50];
int tot, f[50][1<<21];

void solve()
{
	memset(f, 0x3f, sizeof(f));
	//for(int i = 0; i <= n; i++) f[i][0] = 0;
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int tt = 0;
		for(int j = 1; j <= n; j++)
			if(cap[i][j]) tt |= (1 << (j-1));
		tt |= (1 << (i-1));
		for(int S = 0; S < tot; S++)
		{
			f[i][S] = f[i-1][S];
			for(int st = 0; st <= S; st++)
				if((st | tt) == S)
					f[i][S] = min(f[i][S], f[i-1][st]+1);
		}
	}
	printf("%d\n", f[n][tot-1]);
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
		solve();
	}
	return 0;
}
