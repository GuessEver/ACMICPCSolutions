#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		long long A = 0, B = 0;
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			A += x;
		}
		for(int i = 1; i <= m; i++)
		{
			int x; scanf("%d", &x);
			B += x;
		}
		if(A > B) printf("Calem\n");
		else if(A < B) printf("Serena\n");
		else printf("Draw\n");
	}
	return 0;
}
