#include <cstdio>
#include <cstring>

char s[100];
int n;

bool check()
{
	if(n % 3 != 0) return 0;
	int part = n / 3;
	for(int i = 0; i < n; i++)
		if(s[i] != s[i / part * part]) return 0;
	if(s[0] == s[part] || s[0] == s[2 * part] 
			|| s[part] == s[2 * part]) return 0;
	return 1;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		n = strlen(s);
		if(check()) puts("YES"); else puts("NO");
	}
	return 0;
}
