#include <cstdio>
#include <algorithm>

int n, m;
int a[3000];
int maxlen[3000];

int dfs(int x)
{
	if(x * 2 > m) return 0;
	maxlen[x] = std::max(dfs(x*2) + a[x*2], dfs(x*2+1) + a[x*2+1]);
	return maxlen[x];
}

int calc(int x, int nowSum)
{
	if(x * 2 > m) return 0;
	int L = x * 2, R = x * 2 + 1;
	int tmpL = maxlen[x] - (maxlen[L] + a[L]);
	tmpL += calc(x * 2, nowSum + tmpL + a[L]);
	int tmpR = maxlen[x] - (maxlen[R] + a[R]);
	tmpR += calc(x * 2 + 1, nowSum + tmpR + a[R]);
	return tmpL + tmpR;
}

int main()
{
	scanf("%d", &n); n++;
	m = (1 << n) - 1;
	int tot = 0;
	for(int i = 2; i <= m; i++)
	{
		scanf("%d", &a[i]);
		tot += a[i];
	}
	dfs(1);
	printf("%d\n", calc(1, 0));
	return 0;
}
