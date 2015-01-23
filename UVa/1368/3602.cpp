#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1000 + 10;

int n, m;
char a[N][N];
int cnt[N]['z'+10];
char ans[N];

void solve()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%s", a[i]);
		for(int j = 0; j < m; ++j)
		{
			++cnt[j][a[i][j]];
		}
	}
	int cal = 0;
	for(int j = 0; j < m; ++j)
	{
		int A = cnt[j]['A'];
		int C = cnt[j]['C'];
		int G = cnt[j]['G'];
		int T = cnt[j]['T'];
		int _max = std::max(std::max(A, G), std::max(C, T));
		if(_max == A) ans[j] = 'A';
		else if(_max == C) ans[j] = 'C';
		else if(_max == G) ans[j] = 'G';
		else if(_max == T) ans[j] = 'T';
		cal += (A + C + T + G) - _max;
	}
	printf("%s\n", ans);
	printf("%d\n", cal);
}

int main()
{
	freopen("3602.in", "r", stdin);
	//freopen("3602.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--)
	{
		solve();
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		memset(cnt, 0, sizeof(cnt));
	}
	return 0;
}
