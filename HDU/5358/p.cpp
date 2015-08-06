#include <cstdio>
#include <cmath>

const int N = 100000 + 10;

int n, a[N], S[N];

int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d", &n); S[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			S[i] = S[i-1] + a[i];
		}
		long long res = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++)
			{
				int L = 0;
				if(S[j] - S[i-1]) L = log(S[j] - S[i-1]) / log(2.0);
				long long tmp = (L + 1) * (i + j);
				//printf("(%d + 1) * %d = %lld\n", L, i + j, tmp);
				res += tmp;
			}
		printf("%lld\n", res);
	}
	return 0;
}
