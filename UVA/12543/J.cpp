#include <cstdio>
#include <cctype>
#include <cstring>

char s[10000+10];
char ans[10000+10];
int len, maxlen;

int main()
{
	maxlen = 0;
	while(scanf("%s", s) == 1)
	{
		if(!strcmp(s, "E-N-D")) break;
		len = strlen(s);
		while(len > 0 && !isalpha(s[len-1])) len--;
		if(s[0] == '(') len--;
		if(len > maxlen)
		{
			maxlen = len;
			strcpy(ans, s);
		}
	}
	len = strlen(ans);
	for(int i = 0; i < len; i++)
	{
		if(isalpha(ans[i]))putchar(tolower(ans[i]));
		else if(ans[i] == '-') putchar(ans[i]);
	}
	puts("");
	return 0;
}
