#include <cstdio>
const int N = 100000 + 10;

int n, d1, d2;
int a[N];
int L[N], R[N];

int main()
{
	while(scanf("%d%d%d", &n, &d1, &d2) == 3)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		L[1] = 1;
		for(int i = 2; i <= n; i++)
			if(a[i-1] + d1 == a[i]) L[i] = L[i-1] + 1;
			else L[i] = 1;
		R[n] = 1;
		for(int i = n - 1; i >= 1; i--)
			if(a[i+1] == a[i] + d2) R[i] = R[i+1] + 1;
			else R[i] = 1;
		//for(int i = 1; i <= n; i++) printf("%d ", L[i]); puts("");
		//for(int i = 1; i <= n; i++) printf("%d ", R[i]); puts("");
		long long res = 0;
		for(int i = 1; i <= n; i++)
		{
			if(d1 != d2) res += 1ll * L[i] * R[i];
			else res += 1ll * L[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
