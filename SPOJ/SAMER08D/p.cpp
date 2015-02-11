#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using std::queue;

const int N = 1000 + 10;
// 真特么脑袋秀逗了...TAT
int K;
char s[N], t[N];
int lens, lent, n;
int f[N][N];

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
				f[i][j] = std::max(f[i-1][j], f[i][j-1]);
				int cnt = 0;
				while(i-cnt > 0 && j-cnt > 0 && s[i-cnt] == t[j-cnt])
				{
					if(cnt+1 >= K && f[i-cnt-1][j-cnt-1] + 1 + cnt > f[i][j])
						f[i][j] = f[i-cnt-1][j-cnt-1] + 1 + cnt;
					cnt++;
				}
			}
		//for(int i = 1; i <= lens; i++)
		//	for(int j = 1; j <= lent; j++)
		//		printf("%d,%d : %d\n", i, j, f[i][j]);
		printf("%d\n", f[lens][lent]);
	}
	return 0;
}
