#include <cstdio>

int n, a[20], cnt[10];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%1d", &a[i]);
		cnt[a[i]]++;
	}
	cnt[3] += cnt[4];
	cnt[2] += cnt[4] * 2;
	cnt[4] = 0;

	cnt[5] += cnt[6];
	cnt[3] += cnt[6];
	cnt[6] = 0;
	
	cnt[7] += cnt[8];
	cnt[2] += cnt[8] * 3;
	cnt[8] = 0;

	cnt[3] += cnt[9] * 2;
	cnt[2] += cnt[9];
	cnt[7] += cnt[9];
	cnt[9] = 0;

	for(int i = 9; i > 1; i--)
		for(int j = 1; j <= cnt[i]; j++) printf("%d", i);
	puts("");
	return 0;
}
