#include <cstdio>

int n, m, c;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &n, &c, &m);
		int res = n / c, w = n / c;
		while(w >= m)
		{
			int tmp = w / m;
			w = w - tmp * m + tmp;
			res += tmp;
		}
		printf("%d\n", res);
	}
	return 0;
}
