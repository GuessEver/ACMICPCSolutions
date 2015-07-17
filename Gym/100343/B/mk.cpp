#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

int main()
{
	srand(time(0));
	freopen("financial.in", "w", stdout);
	int n = 70, k = 100;
	printf("%d %d\n", n, k);
	for(int i = 1; i < n; i++) printf("%d ", rand()%100+1);
	printf("%d\n", rand()%100+1);
	return 0;
}
