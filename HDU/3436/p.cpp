#include <cstdio>

int n, q;
char op[100];
int a[100000];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case %d:\n", cas);
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++) a[i] = i;
		while(q--)
		{
			int x; scanf("%s%d", op, &x);
			if(op[0] == 'T') // Top
			{
				int k = 1;
				while(a[k] != x) k++;
				int tmp = a[k];
				for(int i = k; i > 1; i--) a[i] = a[i-1];
				a[1] = tmp;
			}
			else if(op[0] == 'Q') // Query
			{
				for(int i = 1; i <= n; i++)
					if(a[i] == x)
					{
						printf("%d\n", i);
						break;
					}
			}
			else printf("%d\n", a[x]); // Rank
		}
	}
	return 0;
}
