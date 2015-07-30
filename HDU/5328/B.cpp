#include <cstdio>

const int N = 1000000 + 10;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if(n == 1 || n == 2)
		{
			printf("%d\n", n);
			continue;
		}
		int ans = 2;
		for(int i = 1; i + 1 <= n; i++)
		{
			int tmp = a[i+1] - a[i], cnt = 1;
			while(i + 1 <= n && a[i+1] - a[i] == tmp)
			{
				cnt++; i++;
			} i--;
			if(cnt > ans) ans = cnt;
		}
		for(int i = 1; i + 2 <= n; i++)
		{
			int cnt = 2;
			while(i + 2 <= n && 1ll * a[i] * a[i+2] == 1ll * a[i+1] * a[i+1])
			{
				cnt++; i++;
			}
			if(cnt > ans) ans = cnt;
		}
		printf("%d\n", ans);
	}
	return 0;
}
