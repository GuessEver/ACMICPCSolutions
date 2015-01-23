#include <cstdio>

int main()
{
	freopen("H.in", "w", stdout);
	int t = 100000;
	printf("%d\n", t);
	int n = 100000, m = 1;
	for(int i = 1; i <= t; i++, m++)
	{
		printf("%d %d\n", n, m);
	}
	return 0;
}
