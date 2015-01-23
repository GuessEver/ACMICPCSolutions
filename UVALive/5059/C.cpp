#include <cstdio>

int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		long long res = 0;
		for(int i = 1; i <= n; i++)
		{
			long long x; scanf("%lld", &x);
			if(x % 2 == 0) x /= 2;
			else while(1)
			{
				bool flag = 0;
				if(x % 2 == 0) flag = 1;
				x /= 2;
				if(flag) break;
			}
			//printf("%d : x = %lld\n", i, x);
			res ^= x;
		}
		if(res) puts("YES"); else puts("NO");
	}
	return 0;
}
