#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int n, f[N], g[N][30];

int calc(int x, int n)
{
	if(x == 1)
	{
		if(n >= 1) return 1;
		else return 0;
	}
	else if(x == 2)
	{
		if(n >= 2) return 1;
		else return 0;
	}
	else if(x == 3)
	{
		if(n >= 3) return 2;
		else if(n >= 2) return 1;
		else return 0;
	}
	if(g[x][n] != -1) return g[x][n];
	g[x][n] = 0;
	for(int i = n; i >= 3; i--)
		if(x >= f[i])
		{
			if(x == f[i])
			{
				g[x][n] = calc(f[i-2], i - 1) + 1;
				break;
			}
			else {
				g[x][n] += calc(x - f[i], i - 1);
			}
		}
	return g[x][n];
}

int main()
{
	f[1] = 1; f[n = 2] = 2;
	for(n = 3; ; n++)
	{
		f[n] = f[n-1] + f[n-2];
		if(f[n] >= 100000) break;
	}
	int T; scanf("%d", &T);
	memset(g, -1, sizeof(g));
	while(T--)
	{
		int x; scanf("%d", &x);
		printf("%d\n", calc(x, n));
	}
	return 0;
}
