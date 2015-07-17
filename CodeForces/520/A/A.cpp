#include <cstdio>
#include <cctype>

int cnt['z'+10], n;
char s[200];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; s[i]; i++) cnt[tolower(s[i])]++;
	for(char i = 'a'; i <= 'z'; i++)
		if(!cnt[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
