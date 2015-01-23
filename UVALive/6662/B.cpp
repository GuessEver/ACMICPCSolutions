#include <cstdio>
#include <cstring>

int n, L;
char tmp[10], pos[200];

int main()
{
	freopen("B.in", "r", stdin);
	while(scanf("%d%d", &n, &L) == 2 && (n || L))
	{
		memset(pos, 0, sizeof(pos));
		memset(pos, '.', sizeof(pos[0])*(L+1));
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", tmp);
			int x; scanf("%d", &x);
			pos[x] = tmp[0];
		}
		puts(pos);
	}
	return 0;
}
