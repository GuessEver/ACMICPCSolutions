#include <cstdio>
#include <cstring>

int n;
char s[110][110];
int len[110];

bool check(int l)
{
	for(int i = 1; i <= n; i++)
		if(len[i]-l == 0) return 1;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(strcmp(s[i]+l, s[j]+l) == 0) return 1;
	return 0;
}

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		memset(s, 0, sizeof(s));
		int minlen = 200;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", s[i]);
			len[i] = strlen(s[i]);
			if(len[i] < minlen) minlen = len[i];
		}
		for(int res = 1; res <= minlen; res++)
		{
			if(check(res))
			{
				printf("%d\n", res-1);
				break;
			}
		}
	}
	return 0;
}
