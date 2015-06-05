#include <cstdio>
#include <cstring>

const long long mod = 1000000000 + 7;

int n, f[2][3];
char now, pre;

int main()
{
	scanf("%d", &n); scanf(" %c", &pre);
	f[0][0] = f[0][1] = f[0][2] = 1;
	for(int i = 2; i <= n; i++)
	{
		scanf(" %c", &now);
		if(now == '0')
		{
			f[1][0] = f[0][2];
			if(pre == '1') f[1][1] = f[0][0];
			else f[1][1] = f[0][1];
			f[1][0] %= mod; f[1][1] %= mod;
			f[1][2] = (f[1][0] + f[1][1]) % mod;
		}
		else {
			f[1][1] = f[0][2];

			f[1][0] = f[0][2];
			if(pre == '1') f[1][0] += f[0][0];
			else f[1][0] += f[0][1];

			f[1][0] %= mod; f[1][1] %= mod;
			f[1][2] = f[1][1] % mod;
		}
		pre = now;
		f[0][0] = f[1][0]; f[0][1] = f[1][1]; f[0][2] = f[1][2];
	}
	printf("%d\n", f[0][2]);
	return 0;
}
