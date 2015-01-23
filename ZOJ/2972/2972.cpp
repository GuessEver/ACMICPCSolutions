#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 110 + 10;

int n, m;
int f[N][N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		memset(f, 0x3f, sizeof(f));
		f[0][m] = 0;
		for(int i = 0; i < n; i++)
		{
			int t1, t2, t3, f1, f2;
			scanf("%d%d%d%d%d", &t1, &t2, &t3, &f1, &f2);
			for(int j = 0; j <= m; j++)
			{
				// fast
				if(j - f1 >= 0)
					f[i+1][j-f1] = std::min(f[i+1][j-f1], f[i][j] + t1);
				// normal
				f[i+1][j] = std::min(f[i+1][j], f[i][j] + t2);
				// slow
				if(j + f2 <= m)
					f[i+1][j+f2] = std::min(f[i+1][j+f2], f[i][j] + t3);
				if(j + f2 > m)
				   	f[i+1][m] = std::min(f[i+1][m], f[i][j] + t3);
			}
		}
		int ans = 0x3f3f3f3f;
		for(int j = 0; j <= m; j++)
		{
			//printf("%d ", f[n][j]);
			ans = std::min(ans, f[n][j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
