#include <cstdio>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a % 2 == 0 || b % 2 == 1) printf("yes\n");
	else printf("no\n");
	return 0;
}
