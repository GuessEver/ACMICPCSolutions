#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int a[200000+10];

int main()
{
	srand(time(0));
	int n = 200000, m = n - 1;
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; i++) a[i] = i;
	std::random_shuffle(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	std::random_shuffle(a + 1, a + 1 + n);
	for(int i = 1; i <= m; i++) printf("%d ", a[i]); puts("");
	return 0;
}
