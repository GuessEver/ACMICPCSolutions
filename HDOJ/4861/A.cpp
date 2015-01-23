#include <cstdio>

int n, p;

int main()
{
	while(scanf("%d%d", &n, &p) == 2)
	{
		int tmp = n / (p - 1);
		if(tmp & 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
