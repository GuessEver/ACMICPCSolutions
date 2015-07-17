#include <cstdio>

int main()
{
	int a, b, c, d, e, f, n;
	int res = 0;
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d%d%d", &d, &e, &f);
	scanf("%d", &n);
	res += (a+b+c) / 5;
	if((a+b+c) % 5 != 0) res++;
	res += (d+e+f) / 10;
	if((d+e+f) % 10 != 0) res++;
	if(res <= n) printf("YES\n");
	else printf("NO\n");
	return 0;
}
