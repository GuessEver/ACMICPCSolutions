#include <cstdio>
#include <cstring>

char s[100000 + 10];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		int len = strlen(s);
		int cnt = 0;
		for(int i = 0; i < len; i++)
			if(i == 0 || s[i] != s[i-1]) cnt++;
		printf("%d\n", len - cnt);
	}
	return 0;
}
