#include <cstdio>
#include <cstring>

const int N = (1 << 16) + 10;
int n, cap[50];
int tot;
bool cc[N];
int f[N];

bool check(int S)
{
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int x = S & 1; S >>= 1;
		if(x) res |= cap[i];
	}
	return res == tot - 1;
}

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		tot = (1 << n);
		memset(cap, 0, sizeof(cap));
		for(int i = 0; i < n; i++)
		{
			int m; scanf("%d", &m);
			while(m--)
			{
				int x; scanf("%d", &x);
				cap[i] |= (1 << x);
			}
			cap[i] |= (1 << i);
		}
		for(int S = 0; S < tot; S++) cc[S] = check(S);
		memset(f, 0, sizeof(f));
		for(int S = 0; S < tot; S++) if(cc[S])
		{
			f[S] = 1;
			for(int st = S; st; st = (st - 1) & S) if(st != S && cc[S ^ st])
				if(f[st] + 1 > f[S]) f[S] = f[st] + 1;
		}
		int res = 0;
		for(int S = 0; S < tot; S++)
			if(f[S] > res) res = f[S];
		printf("Case %d: %d\n", ++cas, res);
	}
	return 0;
}
