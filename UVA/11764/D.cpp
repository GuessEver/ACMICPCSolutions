#include <cstdio>

int n, a[100];

int main()
{
	freopen("D.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case %d: ", cas);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int A = 0, B = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i] < a[i+1]) A++;
			else if(a[i] > a[i+1]) B++;
		}
		printf("%d %d\n", A, B);
	}
	return 0;
}
