#include <cstdio>
#include <cstdlib>
#include <cstring>

char s[10000+10];
int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s);
		n = strlen(s);
		int res = 0;
		for(int i = 0, j = n-1; i < j; i++, j--)
		{
			res += abs(s[i] - s[j]);
		}
		printf("%d\n", res);
	}
	return 0;
}
