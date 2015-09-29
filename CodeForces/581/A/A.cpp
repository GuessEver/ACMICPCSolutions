#include <cstdio>
#include <algorithm>

int main()
{
	int a, b; scanf("%d%d", &a, &b);
	int res1 = std::min(a, b);
	int res2 = (std::max(a, b) - res1) / 2;
	printf("%d %d\n", res1, res2);
	return 0;
}
