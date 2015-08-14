#include <cstdio>

int n, m;
int cnt[200];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int k = -1, max = -1;
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			if(max == -1 || x > max)
			{
				max = x;
				k = i;
			}
		}
		cnt[k]++;
	}
	int k = -1;
	for(int i = 1; i <= n; i++) if(k == -1 || cnt[i] > cnt[k]) k = i;
	printf("%d\n", k);
	return 0;
}
