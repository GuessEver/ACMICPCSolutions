#include <cstdio>
#include <cstring>

const int N = 100 + 10;

int n, a[N], cnt[N];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		memset(cnt, 0, sizeof(cnt));
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if(cnt[a[i]] == 0) res++;
			cnt[a[i]]++;
		}
		int q; scanf("%d", &q);
		while(q--)
		{
			int k = -1;
			for(int i = 1; i <= n; i++)
				if(k == -1 || cnt[i] > cnt[k]) k = i;
			cnt[k]--;
			if(cnt[k] == 0) res--;
		}
		printf("%d\n", res);
	}
	return 0;
}
