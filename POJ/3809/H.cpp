#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = (1<<11) + 10;

int n, m, tot;
int obj[130];
int f[N][N];

int solve(int ask, int ans)
{
	if(f[ask][ans] != -1) return f[ask][ans];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += (ask & obj[i]) == ans;
	if(cnt <= 1) return f[ask][ans] = 0;
	int &tmp = f[ask][ans]; tmp = m;
	for(int j = 0; j < m; j++) if(!(ask & (1 << j)))
		tmp = std::min(tmp, std::max(solve(ask|(1<<j), ans)+1, solve(ask|(1<<j), ans|(1<<j))+1));
	return tmp;
}

int main()
{
	while(scanf("%d%d", &m, &n) == 2 && (n || m))
	{
		tot = (1 << m);
		for(int i = 1; i <= n; i++)
		{
			obj[i] = 0;
			for(int j = 0; j < m; j++)
			{
				int x; scanf("%1d", &x);
				if(x) obj[i] |= (1 << j);
			}
			//printf("%d\n", obj[i]);
		}
		memset(f, -1, sizeof(f));
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
