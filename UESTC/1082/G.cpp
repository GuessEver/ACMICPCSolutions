#include <cstdio>
#include <cstring>

const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int getID(char ch)
{
	for(int i = 0; alpha[i]; i++)
		if(alpha[i] == ch) return i;
}

int n;
char s[100];
int a[100];

int main()
{
	while(scanf("%d", &n) == 1 && n)
	{
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i < len; i++)
		{
			a[i] = getID(s[i]);
			a[i] = (a[i] + n) % 28;
		}
		for(int i = len - 1; i >= 0; i--) putchar(alpha[a[i]]);
		puts("");
	}
	return 0;
}
