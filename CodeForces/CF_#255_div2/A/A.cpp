#include <cstdio>

int n, p;
int h[1000];

int main()
{
	freopen("A.in", "r", stdin);
	scanf("%d%d", &p, &n);
	for(int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		a %= p;
		if(h[a])
		{
			printf("%d\n", i);
			return 0;
		}
		else h[a] = i;
	}
	printf("-1\n");
	return 0;
}
