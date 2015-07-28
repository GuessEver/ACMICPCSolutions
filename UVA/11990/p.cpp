#include <cstdio>

const int N = 200000 + 10;

int n, q, a[N], pos[N];
bool del[N];

long long calc()
{
	long long res = 0;
	for(int i = 1; i <= n; i++) if(!del[i])
		for(int j = i + 1; j <= n; j++) if(!del[j])
			res += (a[i] > a[j]);
	return res;
}

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	while(q--)
	{
		printf("%lld\n", calc());
		int x; scanf("%d", &x);
		del[pos[x]] = 1;
	}
	return 0;
}
