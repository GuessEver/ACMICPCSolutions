#include <cstdio>
#include <algorithm>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if(n > m) std::swap(n, m);
	if(n & 1) printf("Akshat\n");
	else printf("Malvika\n");
	return 0;
}
