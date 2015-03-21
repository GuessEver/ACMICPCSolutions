#include <cstdio>
#include <cstring>

const int N = 20 * 2 + 10;

int n, tot, a[N][N];
long long f[N][N][510];
int ans;
char path[N];

void dfs(int i, int j, int s, int idx)
{
	if(i == 2 * n - 1) return;
	if(i < n)
	{
		if(f[i+1][j-1][s-a[i][j]])
		{
			path[idx] = 'L';
			dfs(i+1, j-1, s-a[i][j], idx+1);
		}
		else{
			path[idx] = 'R';
			dfs(i+1, j, s-a[i][j], idx+1);
		}
	}
	else{
		if(f[i+1][j][s-a[i][j]])
		{
			path[idx] = 'L';
			dfs(i+1, j, s-a[i][j], idx+1);
		}
		else{
			path[idx] = 'R';
			dfs(i+1, j+1, s-a[i][j], idx+1);
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &tot) == 2 && (n || tot))
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n - i + 1; j++)
				scanf("%d", &a[i][j]);
		for(int i = n + 1; i < 2 * n; i++)
			for(int j = 1; j <= i - n + 1; j++)
				scanf("%d", &a[i][j]);
		memset(f, 0, sizeof(f));
		for(int j = 1; j <= n; j++) f[2*n-1][j][a[2*n-1][j]] = 1;
		for(int i = 2 * n - 2; i >= n; i--)
			for(int j = 1; j <= i - n + 1; j++)
				for(int s = a[i][j]; s <= tot; s++)
				{
					f[i][j][s] += f[i+1][j][s-a[i][j]];
					if(j < i-n+1+1) f[i][j][s] += f[i+1][j+1][s-a[i][j]];
				}
		for(int i = n - 1; i >= 1; i--)
			for(int j = 1; j <= n - i + 1; j++)
				for(int s = a[i][j]; s <= tot; s++)
				{
					if(j > 1) f[i][j][s] += f[i+1][j-1][s-a[i][j]];
					f[i][j][s] += f[i+1][j][s-a[i][j]];
				}
		//for(int j = 1; j <= n; j++) printf("%lld ", f[2*n-1][j][tot]); puts("");
		long long res = 0;
		for(int j = 1; j <= n; j++) res += f[1][j][tot];
		if(res)
		{
			for(int j = 1; j <= n; j++) if(f[1][j][tot])
			{
				memset(path, 0, sizeof(path));
				dfs(1, j, tot, 0);
				printf("%lld\n%d %s\n", res, j - 1, path);
				break;
			}
		}
		else printf("0\n\n");
	}
	return 0;
}
