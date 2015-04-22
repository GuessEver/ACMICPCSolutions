#include <cstdio>
#include <cstring>
#include <algorithm>

long long fac[20];
char s[100];
int n, cnt[30];
long long k;

int main()
{
	fac[0] = 1;
	for(int i = 1; i <= 18; i++) fac[i] = fac[i-1] * i;
	while(scanf("%s%lld", s, &k) == 2)
	{
		if(!strcmp(s, "#") && k == 0) break;
		n = strlen(s);
		for(int i = 0; i < n; i++) cnt[s[i]-'A']++;
		for(int i = 1; i <= n; i++)
		{
			long long sum = 0, tmp = 0;
			for(int j = 0; j < 26; j++) if(cnt[j])
			{
				tmp = fac[n - i] / fac[cnt[j] - 1];
				for(int t = 0; t < 26; t++) if(j != t) tmp /= fac[cnt[t]];
				if(sum + tmp >= k)
				{
					putchar(j + 'A');
					cnt[j]--;
					k -= sum;
					break;
				}
				sum += tmp;
			}
		}
		puts("");
	}
	return 0;
}
