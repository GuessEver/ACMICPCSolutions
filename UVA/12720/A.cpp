#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1e9 + 7;

char s[3000000];
char tmp[3000000];

void solve()
{
	scanf("%s", s);
	int len = strlen(s);
	int i, j;
	int cnt = 0;
	if(len & 1)
	{
		int pos = len / 2;
		i = pos - 1;
		j = pos + 1;
		tmp[cnt++] = s[pos];
	}
	else { i = len / 2 - 1; j = i + 1; }
	while(i >= 0 && j < len)
	{
		if(s[i] < s[j]) std::swap(s[i], s[j]);
		tmp[cnt++] = s[i];
		tmp[cnt++] = s[j];
		i--; j++;
	}
	long long ans = 0, k = 1;
	for(int i = cnt - 1; i >= 0; i--)
	{
		ans = (ans + (tmp[i] - '0') * k % mod) % mod;
		k = (k * 2) % mod;
	}
	printf("%lld\n", ans % mod);
}

int main()
{
	//freopen("A.in", "r", stdin);
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		printf("Case #%d: ", cas);
		solve();
	}
	return 0;
}
