#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;

const int N = 1000 + 10;

int K;
char s[N], t[N];
int lens, lent, n;
int f[N][N], g[N][N];
int o[N];

int main()
{
	while(scanf("%d", &K) == 1 && K)
	{
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		memset(o, 0, sizeof(o));
		scanf("%s", s+1); lens = strlen(s+1);
		scanf("%s", t+1); lent = strlen(t+1);
		//printf("%d %d\n", lens, lent);
		for(int i = 1; i <= lens; i++)
			for(int j = 1; j <= lent; j++)
			{
				g[i][j] = 1;
				f[i][j] = std::max(f[i-1][j], f[i][j-1]);
				if(s[i] == t[j] && f[i][j] <= f[i-1][j-1] + 1)
				{
					f[i][j] = f[i-1][j-1] + 1;
					if(s[i-1] == t[j-1] && g[i][j] < g[i-1][j-1] + 1)
						g[i][j] = g[i-1][j-1] + 1;
				}
			}
		//for(int i = 1; i <= lens; i++)
		//	for(int j = 1; j <= lent; j++)
		//		if(g[i][j] >= K)
		//		printf("%d,%d : f =  %d, g = %d\n", i, j, f[i][j], g[i][j]);
		int res = 0;
		o[0] = 1;
		for(int i = 1; i <= lens; i++)
			for(int j = 1; j <= lent; j++)
				if(g[i][j] >= K && o[f[i][j] - g[i][j]])
				{
					o[f[i][j]] = 1;
					if(f[i][j] > res) res = f[i][j];
				}
		printf("%d\n", res);
	}
	return 0;
}
