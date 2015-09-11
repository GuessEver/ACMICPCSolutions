#include <cstdio>

int n, x;

int main()
{
	scanf("%d%d", &n, &x);
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(x % i == 0 && x / i >= 1 && x / i <= n) res++;
	printf("%d\n", res);
	return 0;
}
