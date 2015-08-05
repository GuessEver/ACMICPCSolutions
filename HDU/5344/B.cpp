#include <cstdio>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, m, l, z;
		int ans = 0, a = 0;
		scanf("%d%d%d%d", &n, &m, &z, &l);
		for(int i = 1; i <= n; i++)
		{
			ans ^= (a + a);
			a = (1ll * a * m + z) % l;
		}
		printf("%d\n", ans);
	}
	return 0;
}
