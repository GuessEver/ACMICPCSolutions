#include <cstdio>

int n, q[20], c[20], p[20];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	int k = 0;
	for(int i = 1; i <= n; i++)
	{
		int tmp = q[i] / c[i];
		if(q[i] % c[i] != 0) tmp++;
		if(tmp > k) k = tmp;
	}
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += (1ll * c[i] * k - q[i]) * p[i];
	}
	printf("%I64d\n", res);
	return 0;
}
