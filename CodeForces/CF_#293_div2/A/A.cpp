#include <cstdio>
#include <cstring>

char s[200], t[200], ans[200];
int a[200];
int len, n;

int main()
{
	scanf("%s%s", s, t);
	len = strlen(s);
	for(int i = len - 1; i >= 0; i--) a[n++] = s[i] - 'a';
	a[0]++;
	for(int i = 0; i < len; i++)
	{
		a[i+1] += a[i] / 26;
		a[i] %= 26;
	}
	if(a[len]) puts("No such string");
	else{
		for(int i = len - 1, j = 0; j < len; i--, j++)
			ans[j] = a[i] + 'a';
		ans[len] = 0;
		if(strcmp(ans, t) == 0) puts("No such string");
		else puts(ans);
	}
	return 0;
}
