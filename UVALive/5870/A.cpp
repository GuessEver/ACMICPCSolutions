#include <cstdio>
#include <cstring>
#include <cstdlib>

int a[2000][2000];
int m, b[2000], c[2000];
char s[2000];
int cnt = 0;

void dfs(int x, int val)
{
	if(x > m) return;
	c[++cnt] = val;
	if(val == b[x]) x++;
	if(val > b[x]) val--;
	else if(val < b[x]) val++;
	dfs(x, val);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int maxp = 0;
		cnt = 0; m = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		scanf("%s", s);
		int len = strlen(s);
		for(int i = len - 1; i >= 0; i--)
		{
			b[++m] = s[i] - '0';
			if(b[m] > maxp) maxp = b[m];
		}
		dfs(1, b[1]);
	//	for(int i = cnt; i >= 1; i--) printf("%d ", c[i]);
	//	puts("");
		for(int i = 1; i <= cnt; i++)
			for(int j = 1; j <= c[i]; j++) a[j][i] = 1;
		for(int j = maxp; j >= 1; j--)
		{
			for(int i = cnt; i >= 1; i--)
				putchar(a[j][i] ? '+' : '*');
			puts("");
		}
	}
	return 0;
}
