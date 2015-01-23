#include <cstdio>

int n, x;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		scanf("%d", &x);
		for(int i = 2; i <= n; i++)
		{
			int a; scanf("%d", &a);
			x = gcd(x, a);
		}
		if(x == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}
