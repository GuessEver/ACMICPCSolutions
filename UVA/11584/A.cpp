#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000 + 10;

int n, f[N];
bool p[N][N];
char s[N];

void pre()
{
	memset(p, 0, sizeof(p));
	for(int k = 1; k <= n; k++) // odd
		for(int i = 0; k - i >= 1 && k + i <= n; i++)
			if(s[k-i] == s[k+i]) p[k-i][k+i] = 1;
			else break;
	for(int k = 1; k < n; k++) if(s[k] == s[k + 1]) // even
		for(int i = 0; k - i >= 1 && k + i + 1 <= n; i++)
			if(s[k-i] == s[k+1+i]) p[k-i][k+1+i] = 1;
			else break;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1); n = strlen(s+1);
		pre();
		memset(f, 0x3f, sizeof(f)); f[0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < i; j++)
				if(p[j+1][i] && f[i] > f[j] + 1)
					f[i] = f[j] + 1;
		printf("%d\n", f[n]);
	}
	return 0;
}
