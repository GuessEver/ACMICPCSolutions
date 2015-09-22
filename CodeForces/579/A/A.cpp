#include <cstdio>

int main()
{
	int x; scanf("%d", &x);
	int cnt = 0;
	while(x) { cnt += (x & 1); x >>= 1; }
	printf("%d\n", cnt);
	return 0;
}
