#include <cstdio>

const int N = 100000 + 10;

int n, a[N];
int f[N], g[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= a[i-1]) f[i] = f[i-1] + 1;
		else f[i] = 1;
	}
	for(int i = n; i >= 1; i--)
	{
		if(a[i] <= a[i+1]) g[i] = g[i+1] + 1;
		else g[i] = 1;
	}
	//for(int i = 1; i <= n+1; i++) printf("%d ", f[i]); puts("");
	//for(int i = 1; i <= n+1; i++) printf("%d ", g[i]); puts("");
	if(f[n] == n)
	{
		printf("0\n");
		return 0;
	}
	for(int i = n-1; i >= 1; i--)
	{
		if(g[i+1] + f[i] == n && a[i+g[i+1]] <= a[1])
		{
			printf("%d\n", g[i+1]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
