#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int n, m;
int to[N];
double f[N];

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		memset(to, 0, sizeof(to));
		for(int i = 1; i <= m; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			to[x] = y;
		}
		f[n] = 0;
		for(int i = n-1; i >= 0; i--)
		{
			if(to[i]) f[i] = f[to[i]];
			else{
				f[i] = 1;
				for(int k = 1; k <= 6 && i + k <= n; k++)
					f[i] += f[i+k] / 6.0;
			}
		}
		printf("%.4f\n", f[0]);
	}
	return 0;
}
