#include <cstdio>
#include <cstring>

const int N = 16 + 10;

int n, can[N], tot;
long long f[1<<17];
int weapon[1<<17];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		tot = 1 << n;
		memset(can, 0, sizeof(can));
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < n; j++)
			{
				int x; scanf("%1d", &x);
				if(x) can[i] |= (1 << j);
			}
		for(int S = 0; S < tot; S++)
		{
			weapon[S] = can[0];
			for(int i = 1; i <= n; i++)
				if((S & (1 << (i-1))) != 0)
					weapon[S] |= can[i];
		}
		memset(f, 0, sizeof(f)); f[0] = 1;
		for(int S = 0; S < tot; S++)
			for(int j = 0; j < n; j++)
				if((S & (1 << j)) == 0 && (weapon[S] & (1 << j)) != 0)
					f[S|(1<<j)] += f[S];
		printf("Case %d: %lld\n", cas, f[tot-1]);
	}
	return 0;
}
