#include <cstdio>

int n, m, deg[10000000];

int main()
{
	scanf("%*s");
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		deg[x]++; deg[y]++;
	}
	for(int i = 1; i <= n; i++) if(deg[i] != deg[1])
		printf("Different at deg[%d] = %d\n", i, deg[i]);
	printf("Done with degree %d\n", deg[1]);
	return 0;
}
