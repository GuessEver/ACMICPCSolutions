#include <cstdio>
#include <algorithm>

int n, m, p, q;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &n, &m, &p, &q);
		int res1 = n * p;
		int cas = n / m;
		int res2 = cas * q + std::min((n - cas * m) * p, q);
		printf("%d\n", std::min(res1, res2));
	}
	return 0;
}
