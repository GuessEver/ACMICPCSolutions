#include <cstdio>
#include <cstring>

char s[200010];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	int n = 0;
   	if(len > 1) n = (s[len-2] - '0') * 10;
   	n += (s[len-1] - '0');
	n %= 4;
	int ans = 0;
	if(!n) ans = 4;
	printf("%d\n", ans);
	return 0;
}
