#include <cstdio>
#include <cstring>

long long n;
char s[20];
int len;
int a[20];

void solve()
{
	long long ans = 0;
	long long k = 1;
	for(int t = 1; t <= 2; t++)
	{
		k = 1;
		for(int i = 1; i <= len/2; i++)
		{
			int j = len - i + 1;
			int cnt = 0;
			while(a[i] != a[j])
			{
				cnt++;
				a[i]++;
				for(int k = i; k <= len; k++)
				{
					a[k+1] += a[k] / 10;
					a[k] %= 10;
				}
			}
			ans += k * cnt;
			k *= 10;
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		if(!strcmp(s, "0")) break;
		len = strlen(s);
		sscanf(s, "%lld", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= len; i++)
		{
			a[i] = n % 10;
			n /= 10;
		}
		solve();
	}
	return 0;
}
