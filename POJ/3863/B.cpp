#include <cstdio>

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	int res = -1;
	while(m--)
	{
		int u, d; scanf("%d%d", &u, &d);
		// y = ux - (n-x)d = (u+d)x - nd >= 0
		int x = n * d / (u + d);
		for(int i = x - 1; i <= x + 1; i++)
		{
			int y = u * i - (n - i) * d;
			if(y <= 0) continue;
			if(res == -1 || y < res) res = y;
		}
	}
	printf("%d\n", res);
	return 0;
}
