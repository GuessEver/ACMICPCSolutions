#include <cstdio>
const int N = 1000 + 10;
int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int q; scanf("%d", &q);
		while(q--)
		{
			int l, r; scanf("%d%d", &l, &r);
			int res = 0;
			for(int i = l; i <= r; i++) if(a[i] > res) res = a[i];
			printf("%d\n", res);
		}
	}
	return 0;
}
