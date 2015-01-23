#include <cstdio>

const int N = 5000 + 10;

int n;
double a[N], b[N];

int main()
{
	freopen("C.in", "r", stdin);
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%lf%lf", &a[i], &b[i]);
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			double L = -1e10, R = 1e10;
			for(int j = 1; j <= n; j++) if(i != j)
			{
				if(a[i] == a[j])
				{
					if(b[j] - b[i] >= 0)
					{
						L = 1e10; R = -1e10;
						break;
					}
				}
				else if(a[i] - a[j] > 0)
				{
					double nowl = 1.0 * (b[j] - b[i]) / (a[i] - a[j]);
					if(nowl > L) L = nowl;
				}
				else{
					double nowr = 1.0 * (b[j] - b[i]) / (a[i] - a[j]);
					if(nowr < R) R = nowr;
				}
			}
			if(L < R) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
