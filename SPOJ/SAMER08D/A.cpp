#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;

const int N = 1000 + 10;
//重写 TAT
int K;
char s[N], t[N];
int lens, lent, n;
int f[N][N], g[N][N];

int main()
{
	while(scanf("%d", &K) == 1 && K)
	{
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		scanf("%s", s+1); lens = strlen(s+1);
		scanf("%s", t+1); lent = strlen(t+1);
		//printf("%d %d\n", lens, lent);
		for(int i = 1; i <= lens; i++)
			for(int j = 1; j <= lent; j++)
			{
				g[i][j] = 0;
				if(s[i] == t[j]) g[i][j] = g[i-1][j-1] + 1;
			}
		//for(int i = 1; i <= lens; i++)
		//	for(int j = 1; j <= lent; j++)
		//		printf("%d,%d : %d\n", i, j, g[i][j]);
		for(int i = 1; i <= lens; i++)
			for(int j = 1; j <= lent; j++)
			{
				f[i][j] = std::max(f[i-1][j], f[i][j-1]);
				if(g[i][j] >= K && i >= K && j >= K && f[i-K][j-K] + K > f[i][j])
					f[i][j] = f[i-K][j-K] + K;
				if(g[i][j] > K && f[i-1][j-1] + 1 > f[i][j])
					f[i][j] = f[i-1][j-1] + 1;
			}
		//for(int i = 1; i <= lens; i++)
		//	for(int j = 1; j <= lent; j++)
		//		printf("%d,%d : %d\n", i, j, f[i][j]);
		printf("%d\n", f[lens][lent]);
	}
	return 0;
}
