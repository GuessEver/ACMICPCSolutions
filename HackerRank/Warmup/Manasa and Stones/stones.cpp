#include <cstdio>
#include <algorithm>

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		n--;
		if(a > b) std::swap(a, b);
		int res = n * a;
		printf("%d", res);
		if(a != b)
		{
			for(int i = 1; i <= n; i++)
			{
				res -= a;
				res += b;
				printf(" %d", res);
			}
		}
		puts("");
	}
	return 0;
}
