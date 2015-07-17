#include <cstdio>

int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	int idx = 1, sign = 1, K = k;
	for(int i = 1; i <= K+1; i++)
	{
		if(i != 1) putchar(' ');
		printf("%d", idx);
		idx += sign * k;
		sign = -sign; k--;
	}
	for(int i = K + 2; i <= n; i++) printf(" %d", i);
	puts("");
	return 0;
}
