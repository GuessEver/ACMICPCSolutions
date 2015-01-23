#include <cstdio>
#include <cstring>

const int N = 100000 + 10;
const int mod = 1000000007;

char s[N];
int n, pre['Z'+10], f[N];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		memset(s, 0, sizeof(s));
		scanf("%s", s+1);
		n = strlen(s+1);
		//printf("%d\n", n);
		memset(pre, -1, sizeof(pre));
		f[0] = 1;
		for(int i = 1; i <= n; i++)
		{
			f[i] = (f[i-1] * 2ll) % mod;
			if(pre[s[i]] != -1)
				f[i] = ((f[i] - f[pre[s[i]]-1]) % mod + mod) % mod;
			pre[s[i]] = i;
		}
		//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
		printf("%d\n", f[n]);
	}
	return 0;
}
