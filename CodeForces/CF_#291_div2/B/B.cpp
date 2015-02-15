#include <cstdio>
#include <cmath>

int n, x[1010], y[1010];
int sx, sy;
bool hash[1010];

int main()
{
	scanf("%d%d%d", &n, &sx, &sy);
	for(int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
	int res = 0;
	for(int i = 1; i <= n; i++) if(!hash[i])
	{
		hash[i] = 1;
		if(sx != x[i])
		{
			double k = 1.0 * (y[i] - sy) / (x[i] - sx);
			double b = sy - k * sx;
			for(int j = i + 1; j <= n; j++) if(!hash[j])
				if(fabs(k * x[j] + b - y[j]) < 1e-7)
					hash[j] = 1;
		}
		else{
			for(int j = i + 1; j <= n; j++) if(!hash[j])
				if(x[j] == sx) hash[j] = 1;
		}
		res++;
	}
	printf("%d\n", res);
	return 0;
}
