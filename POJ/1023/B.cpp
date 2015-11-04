#include <cstdio>
int m;
long long n;
char s[100], ans[100];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s%lld", &m, s, &n);
		ans[m] = 0;
		for(int i = m - 1; i >= 0; i--)
		{
			if(n & 1)
			{
				ans[i] = '1';
				if(s[i] == 'p') n--;
				else n++;
			}
			else ans[i] = '0';
			n >>= 1;
		}
		if(n) puts("Impossible"); else puts(ans);
	}
	return 0;
}
