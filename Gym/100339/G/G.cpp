#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using std::vector;

const int N = 100 + 10;
const int M = 100 * 200 + 10;

int f[N][M*2];
int n, a[N], tot;
int pre[N][M*2];
vector<int> Q[2];
vector<int>::iterator it;

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		tot += a[i];
	}
	for(int i = 0; i <= n; i++)
		for(int j = -tot + M; j <= tot + M; j++)
			f[i][j] = -0x3f3f3f3f;
	f[0][M] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = tot; j >= -tot; j--)
		{
			if(f[i-1][j+M] < 0) continue;
			if(f[i][j+M] < f[i-1][j+M])
			{
				f[i][j+M] = f[i-1][j+M];
				pre[i][j+M] = j;
			}
			if(j + a[i] <= tot && f[i][j+a[i]+M] < f[i-1][j+M] + 1)
			{
				f[i][j+a[i]+M] = f[i-1][j+M] + 1;
				pre[i][j+a[i]+M] = j;
			}
			if(j - a[i] >= -tot && f[i][j-a[i]+M] < f[i-1][j+M] + 1)
			{
				f[i][j-a[i]+M] = f[i-1][j+M] + 1;
				pre[i][j-a[i]+M] = j;
			}
		}
	/*for(int i = 1; i <= n; i++)
	{
		printf("%d :\n", i);
		for(int j = -tot; j <= tot; j++)
			printf("     %d : %d\n", j, f[i][j+M]);
	}*/
	printf("%d\n", f[n][M]);
	if(!f[n][M]) return 0;
	int sum = 0;
	for(int i = n; i >= 1; i--)
	{
		int len = sum - pre[i][sum+M];
		if(len > 0) Q[0].push_back(len);
		if(len < 0) Q[1].push_back(len);
		sum = pre[i][sum+M];
	}
	int x = 0, y = 0;
	for(int t = 0; t < 2; t++)
	for(it = Q[t].end()-1; it >= Q[t].begin(); it--)
	{
		printf("%d %d\n", x, y);
		x += *it;
		printf("%d %d\n", x, y);
		y++;
	}
	return 0;
}
