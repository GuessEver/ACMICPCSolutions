#include <cstdio>
#include <cstring>

int f(int x)
{
	int res = 0;
	do res += x % 10; while(x /= 10);
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		int l, r; scanf("%d%d", &l, &r);
		int res = 0;
		for(int i = l; i <= r; i++) res += (i % f(i) == 0);
		printf("Case %d: %d\n", cas, res);
	}
	return 0;
}
