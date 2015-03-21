#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = (1 << 11) + 10;

int n, m, cap[128+10];
int f[N][N];

int solve(int ask, int ans)
{
	if(f[ask][ans] != -1) return f[ask][ans];
	int cnt = 0;
	for(int i = 0; i < m; i++) cnt += ((ask & cap[i]) == ans);
	if(cnt <= 1) return f[ask][ans] = 0;
	f[ask][ans] = 0x3f3f3f3f;
	for(int i = 0; i < n; i++) if((ask & (1 << i)) == 0)
		f[ask][ans] = std::min(f[ask][ans], 
				std::max(solve(ask | (1 << i), ans | (1 << i)),
					solve(ask | (1 << i), ans)) + 1);
	return f[ask][ans];
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int j = 0; j < m; j++)
		{
			cap[j] = 0;
			for(int i = 0; i < n; i++)
			{
				int x; scanf("%1d", &x);
				if(x) cap[j] |= (1 << i);
			}
		}
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
