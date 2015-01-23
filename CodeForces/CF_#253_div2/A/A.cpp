#include <cstdio>
#include <cstring>
#include <cctype>

char s[10000];
bool hash['z'+10];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	fgets(s, 2000, stdin);
	int len = strlen(s);
	int res = 0;
	for(int i = 0; i < len; i++)
	{
		if(!isalpha(s[i])) continue;
		if(!hash[s[i]]) res++;
		hash[s[i]] = 1;
	}
	printf("%d\n", res);
	return 0;
}
