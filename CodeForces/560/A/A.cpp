#include <cstdio>
#include <algorithm>

const int N = 1000 + 10;

int n;

int main()
{
	scanf("%d", &n);
	int minx = -1;
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		if(minx == -1 || x < minx) minx = x;
	}
	if(minx == 1) puts("-1");
	else puts("1");
	return 0;
}
