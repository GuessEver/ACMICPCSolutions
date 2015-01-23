#include <cstdio>

const int N = 250 + 10;

int n, m;
char cap[N][N];
int cnt['Z'+10];

int cal(int x) // C(x, 2)
{
	return x * (x-1) / 2;
}

int solve()
{
	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
		{
			cnt['B'] = cnt['J'] = cnt['H'] = cnt['Y'] = cnt['N'] = 0;
			for(int t = 1; t <= m; t++)
				if(cap[i][t] == cap[j][t]) cnt[cap[i][t]]++;
			res += cal(cnt['B']) + cal(cnt['J']) + cal(cnt['H'])
					+ cal(cnt['Y']) + cal(cnt['N']);
		}
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%s", cap[i]+1);
		printf("%d\n", solve());
	}
	return 0;
}
