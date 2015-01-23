#include <cstdio>
#include <cstring>
#include <algorithm>

char s[2000];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int len = strlen(s);
		if(std::next_permutation(s, s+len)) puts(s);
		else puts("no answer");
	}
	return 0;
}
