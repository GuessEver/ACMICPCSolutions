#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

int n;
int f[1010], w[1010][1010];

int main()
{
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		memset(w, 0, sizeof(w));
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if(x + y >= n) continue;
			if(w[x+1][n-y] >= n - y - x) continue;
			w[x+1][n-y]++;
		}
		for(int i = 1; i <= n; i++)
		{
			f[i] = 0;
			for(int j = 0; j < i; j++)
				f[i] = max(f[i], f[j] + w[j+1][i]);
		}
		printf("Case %d: %d\n", ++cas, n - f[n]);
	}
	return 0;
}
