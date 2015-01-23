#include <cstdio>

const int N = 50 + 10;

int n, x, l[N], r[N];

int main()
{
	scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	int now = 1, cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		now += (l[i] - now) / x * x;
		cnt += r[i] - now + 1;
		now = r[i] + 1;
	}
	printf("%d\n", cnt);
	return 0;
}
