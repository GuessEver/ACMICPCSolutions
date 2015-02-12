#include <cstdio>
#include <cstring>

const int N = 400 + 10;

int n, m, a[N], b[N];
int ttt = 0;
int cap[N][N], pre[N];
int vis[N];

bool search(int x)
{
	for(int i = 1; i <= n; i++)
		if(cap[x][i] && vis[i] != ttt)
		{
			vis[i] = ttt;
			if(pre[i] == -1 || search(pre[i]))
			{
				pre[i] = x;
				return 1;
			}
		}
	return 0;
}

int match()
{
	memset(pre, -1, sizeof(pre));
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		++ttt;
		res += search(i);
	}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
		memset(cap, 0, sizeof(cap));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) if(i != j)
				for(int k = 1; k <= m; k++)
					if(a[i] + a[j] == b[k])
						cap[i][j] = 1;
		printf("%d\n", match() / 2);
	}
	return 0;
}
