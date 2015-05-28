#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(0));
	int n = 100; printf("%d\n", n);
	for(int i = 1; i <= n; i++) printf("%d ", rand()%100-rand()%50); puts("");
	int q = 100; printf("%d\n", q);
	while(q--)
	{
		int l = rand()%n+1, r;
		if(l == n) r = n;
		else r = l+rand()%(n-l);
		printf("%d %d\n", l, r);
	}
	return 0;
}
