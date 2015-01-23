#include <cstdio>
#include <algorithm>
using std::max;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int res = max(2 * b + 40, 2 * 39 + 40 + 2 * (a - 40) + 1);
	printf("%d\n", res);
	return 0;
}
