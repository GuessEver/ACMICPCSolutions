#include <cstdio>

const int N = 100000 + 10;
int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		long long res = 0;
		for(int i = 0; i <= 33; i++)
		{
			long long sum1 = 0, sum2 = 0;
			int r1 = 0, r2 = 0;
			long long cnt = 0;
			long long x1 = (1ll << i), x2 = (1ll << (i + 1));
			for(int l = 1; l <= n; l++)
			{
				while(r1 <= n && sum1 + a[r1] < x1) sum1 += a[r1++];
				while(r2 <= n && sum2 + a[r2] < x2) sum2 += a[r2++];
				// sum1 >= x1 && sum2 >= x2
				int len = r2 - r1;
				cnt += 1ll * len * l + 1ll * (r1 + r2 - 1) * len / 2;
				sum1 -= a[l]; sum2 -= a[l];
			}
			res += 1ll * cnt * (i + 1);
			//printf("k = %d : %d\n", i, cnt * (i + 1));
			//printf("res = %lld\n", res);
		}
		for(int l = 1; l <= n; l++) if(a[l] == 0)
		{
			int r = l;
			while(r <= n && a[r] == 0)
			{
				res += 1ll * r * (r - l + 1) + 1ll * (l + r) * (r - l + 1) / 2;
				r++;
			}
			//for( ; r <= n && a[r] == 0; r++)
			//	res += 1ll * r * (r - l + 1) + 1ll * (l + r) * (r - l + 1) / 2;
			l = r;
		}
		printf("%lld\n", res);
	}
	return 0;
}
