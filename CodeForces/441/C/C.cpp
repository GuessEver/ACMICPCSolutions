#include <cstdio>

int n, m, k, K;

int main()
{
	scanf("%d%d%d", &n, &m, &k); K = k;
	int tmp = n * m / k;
	int x = 1, y = 1, d = 1, cnt = 0;
	while(x <= n)
	{
		if(cnt == tmp && k > 1) { puts(""); cnt = 0; k--;}
		if(cnt == 0 && k > 0) printf("%d", k > 1 ? tmp : (n * m - tmp * (K-1)));
		printf(" %d %d", x, y); cnt++;
		y += d;
		if(y == m + 1)
		{
			x++;
			y = m;
			d = -1;
		}
		if(y == 0)
		{
			x++;
			y = 1;
			d = 1;
		}
	}
	puts("");
	return 0;
}
