#include <cstdio>
#include <algorithm>

int n, m;
struct Node{int d, c[100], v;}a[100];
int num[100];

bool cmp(Node x, Node y)
{
	return x.v > y.v;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].d);
			for(int j = 1; j <= a[i].d; j++)
				scanf("%d", &a[i].c[j]);
			scanf("%d", &a[i].v);
		}
		std::sort(a+1, a+1+n, cmp);
		for(int i = 1; i <= m; i++) scanf("%d", &num[i]);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			bool ok = 1;
			while(ok)
			{
				for(int j = 1; j <= a[i].d; j++)
					if(!num[a[i].c[j]]) ok = 0;
				if(!ok) break;
				ans += a[i].v;
				for(int j = 1; j <= a[i].d; j++)
					num[a[i].c[j]]--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
