#include <cstdio>

int n, d;

int main()
{
	scanf("%d%d", &n, &d);
	for(int i = 1; i <= n; i++)
	{
		int ti; scanf("%d", &ti);
		d -= ti;
	}
	if(d < 10 * (n - 1)) puts("-1");
	else{
		printf("%d\n", d / 5);
	}
	return 0;
}
