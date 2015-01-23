#include <cstdio>
#include <cstring>
#include <algorithm>

int n, len[10];
char s[10][20], now[200];
int a[10];
int minAns;

void solve()
{
	memset(now, 0, sizeof(now));
	strcat(now, s[a[1]]);
	int res = strlen(now);
	for(int t = 2; t <= n; t++)
	{
		int cur = a[t];
		int maxp = std::min(len[cur], res);
		int same = 0;
		for(int p = maxp; p >= 0; p--)
		{
			bool flag = 1;
			for(int i = res - p, j = 0; j < p; i++, j++)
				if(now[i] != s[cur][j])
				{
					flag = 0;
					break;
				}
			if(flag) { same = p; break; }
		}
		strcat(now, s[cur]+same);
		res += len[cur] - same;
		//puts(now);
	}
	minAns = std::min(minAns, res);
	//puts("============");
}

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		memset(s, 0, sizeof(s));
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
		}
		for(int i = 1; i <= n; i++) a[i] = i;
		minAns = 0x3f3f3f3f;
		do{
			solve();
		}while(std::next_permutation(a+1, a+1+n));
		printf("Case %d: %d\n", cas, minAns);
	}
	return 0;
}
