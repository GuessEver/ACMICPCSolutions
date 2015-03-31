#include <cstdio>
#include <cstring>

const int N = 10000 + 10;

int n, maxp;
double p, f[N];
bool mine[N];

int main()
{
	while(scanf("%d%lf", &n, &p) == 2)
	{
		memset(mine, 0, sizeof(mine));
		maxp = -1;
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			mine[x] = 1;
			if(x > maxp) maxp = x;
		}
		maxp++; f[1] = 1.0;
		for(int i = 2; i <= maxp; i++)
		{
			f[i] = 0;
			if(mine[i]) continue;
			f[i] = f[i-1] * p + f[i-2] * (1-p);
		}
		printf("%.7f\n", f[maxp]);
	}
	return 0;
}
