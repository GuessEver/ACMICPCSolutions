#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

const int N = 100 + 10;

int n, m, s;
int w[N], cap[N], tot;
char str[1010];
long long f[(1<<16)+10];

void Read(int &money, int &status)
{
	int x; scanf("%d", &x); money += x;
	fgets(str, 1000, stdin);
	for(int i = 0; str[i]; i++)
		if(isdigit(str[i]))
		{
			x = str[i] - '0' - 1;
			if((1 << x) & status) status |= (1 << (x + s));
			else status |= (1 << x);
		}
}

int main()
{
	while(scanf("%d%d%d", &s, &m, &n) == 3 && s)
	{
		tot = (1 << (s*2));
		int start = 0, mon = 0;
		for(int i = 0; i < m; i++) Read(mon, start);
		memset(w, 0, sizeof(w));
		memset(cap, 0, sizeof(cap));
		for(int i = 1; i <= n; i++) Read(w[i], cap[i]);
		memset(f, 0x3f, sizeof(f)); f[start] = mon;
		for(int i = 0; i <= n; i++)
			for(int S = tot - 1; S >= 0; S--)
			{
				int tmp = cap[i], st = S;
				for(int j = 0; j < s; j++)
				{
					int flag = tmp & 1; tmp >>= 1;
					if(!flag) continue;
					if((1 << j) & st) st |= (1 << (j + s));
					else st |= (1 << j);
				}
				f[st] = std::min(f[st], f[S] + w[i]);
			}
		printf("%lld\n", f[tot-1]);
	}
	return 0;
}
