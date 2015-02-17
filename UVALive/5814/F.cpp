#include <cstdio>

int a, b, c;

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if(a <= 20 && b <= 20 && c <= 20)
			printf("Case %d: good\n", cas);
		else printf("Case %d: bad\n", cas);
	}
	return 0;
}
