#include <cstdio>

int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	if(n == 1) printf("1\n");
	else if(m == 1) printf("2\n");
	else if(m == n) printf("%d\n", n - 1);
	else {
		int left = m - 1, right = n - m;
		if(left >= right) printf("%d\n", m - 1);
		else printf("%d\n", m + 1);
	}
	return 0;
}
