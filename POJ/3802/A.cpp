#include <cstdio>
#include <cstring>

int n, m;
int front[20], side[20];
bool vis[20];

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++) scanf("%d", &front[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &side[i]);
		int res = 0;
		for(int i = 1; i <= m; i++)
		{
			int k = -1;
			for(int j = 1; j <= n; j++) if(!vis[j])
				if(front[j] == side[i])
				{
					k = j;
					break;
				}
			if(k != -1) vis[k] = 1;
			res += side[i];
		}
		for(int i = 1; i <= n; i++) if(!vis[i]) res += front[i];
		printf("%d\n", res);
	}
	return 0;
}
