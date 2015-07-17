#include <cstdio>
#include <cstring>

char s[100], t[100];
int n, len;

bool check()
{
	for(int i = 0, j = len-1; i < len/2; i++, j--)
		if(t[i] != t[j]) return 0;
	return 1;
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	for(char ch = 'a'; ch <= 'z'; ch++)
	for(int i = 0; i <= n; i++)
	{
		len = 0;
		for(int j = 0; j < i; j++) t[len++] = s[j];
		t[len++] = ch;
		for(int j = i; j < n; j++) t[len++] = s[j];
		if(check())
		{
			puts(t);
			return 0;
		}
	}
	puts("NA");
	return 0;
}
