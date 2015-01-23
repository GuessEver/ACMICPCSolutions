#include <cstdio>
#include <cstring>

const int N = 2 * (100000 + 10);

int n, a[N];
int sum[N], minval[N];
int que[N], L, R;

int main()
{
	freopen("D.in", "r", stdin);
	int cas = 0;
	while(scanf("%d", &n) == 1 && n)
	{
		memset(minval, 0, sizeof(minval));
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			a[i] -= x;
		}
		for(int i = 1; i <= n; i++) a[i+n] = a[i];
		sum[0] = 0;
		for(int i = 1; i <= 2 * n; i++) sum[i] = sum[i-1] + a[i];
		int kk = -1;
		for(int i = 1; i <= n; i++)
			if(kk == -1 || sum[i] <= sum[kk]) kk = i;
		L = R = 0; que[R++] = kk;
		for(int i = n + 1; i <= 2 * n; i++)
		{
			minval[i-n] = sum[que[L]];
			while(que[L] <= i - n) L++;
			while(R > L && sum[i] <= sum[que[R-1]]) R--;
			que[R++] = i;
		}
		//for(int i = 1; i <= n; i++) printf("%d ", minval[i]); puts("");
		int cnt = 0;
		printf("Case %d: ", ++cas);
		for(int i = 1; i <= n; i++)
		{
			if(minval[i] >= sum[i-1])
			{
				if(cnt) putchar(' ');
				printf("%d", i);
				cnt++;
			}
		}
		puts("");
	}
	return 0;
}
