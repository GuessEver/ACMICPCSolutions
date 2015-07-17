#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 300 + 10;

int n, a[N], pos[N];
int can[N][N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%1d", &can[i][j]);
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(can[i][k] && can[k][j])
					can[i][j] = can[j][i] = 1;
	for(int i = 1; i <= n; i++)
	{
		int k = pos[i];
		for(int j = 1; j < k; j++)
			if(a[j] > a[k] && can[j][k])
			{
				std::swap(a[k], a[j]);
				pos[a[k]] = k;
				pos[a[j]] = j;
			}
	}
	for(int i = 1; i < n; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}
