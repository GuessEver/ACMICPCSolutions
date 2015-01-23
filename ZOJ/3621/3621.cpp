#include <cstdio>
#include <cstring>

char s[1000];
int K;
int KK['z'+10];
int pri[1000], cc[1000], cnt;

long long change(char *s, int k)
{
	int len = strlen(s);
	long long res = 0;
	long long fac = 1;
	for(int i = len-1; i >= 0; i--)
	{
		res += KK[s[i]] * fac;
		fac *= k;
	}
	return res;
}

long long solve(long long S, int K)
{
	memset(pri, 0, sizeof(pri));
	memset(cc, 0, sizeof(cc));
	cnt = 0;
	for(int i = 2; i <= K; i++)
		if(K % i == 0)
		{
			pri[++cnt] = i;
			while(K % i == 0)
			{
				K /= i;
				cc[cnt]++;
			}
		}
	long long ans = -1;
	for(int i = 1; i <= cnt; i++)
	{
		long long res = 0;
		long long tmp = S;
		while(tmp)
		{
			res += tmp / pri[i];
			tmp /= pri[i];
		}
		if(ans == -1 || res / cc[i] < ans) ans = res / cc[i];
	}
	return ans;
}

int main()
{
	int cnt = 0;
	for(char i = '0'; i <= '9'; i++) KK[i] = cnt++;
	for(char i = 'A'; i <= 'Z'; i++) KK[i] = cnt++;
	for(char i = 'a'; i <= 'z'; i++) KK[i] = cnt++;
	while(scanf("%s%d", s, &K) == 2)
	{
		long long ss = change(s, K);
		//printf("%lld\n", ss);
		printf("%lld\n", solve(ss, K));
	}
	return 0;
}
