#include <cstdio>

const int N = 100000 + 10;
const int mod = 1000000000 + 7;

int n, m;
int a[N], b[N], c[N];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) c[i] = 1;
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		c[b[i]] = 1ll * c[b[i]] * x % mod;
	}
	for(int i = 1; i <= n; i++) if(c[i] > 1)
		for(int j = i; j <= n; j += i)
			a[j] = (1ll * a[j] * c[i]) % mod;
	for(int i = 1; i < n; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}
