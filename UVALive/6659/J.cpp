#include <cstdio>
#include <cstring>

char s[2010];
int n;
int num[2010]['z'+10];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%s", s); n = strlen(s);
		for(int i = 0; i < n; i++)
		{
			for(int k = 'a'; k <= 'z'; k++)
				num[i][k] = num[i-1][k];
			num[i][s[i]]++;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
			{
				int odd = 0, even = 0;
				for(int k = 'a'; k <= 'z'; k++)
				{
					int tmp = num[j][k] - num[i-1][k];
					if(tmp&1) odd++;
					else even++;
				}
				if(odd > 1) continue;
				ans++;
			}
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}
