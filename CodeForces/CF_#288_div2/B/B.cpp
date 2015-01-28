#include <cstdio>
#include <algorithm>
#include <cstring>

char s[100010];
int n;

int main()
{
	scanf("%s", s); n = strlen(s);
	int last = s[n-1] - '0';
	for(int i = 0; i < n-1; i++)
	{
		int x = s[i] - '0';
		if(x % 2 == 0 && last >= x)
		{
			std::swap(s[i], s[n-1]);
			puts(s);
			return 0;
		}
	}
	for(int i = n - 2; i >= 0; i--)
	{
		int x = s[i] - '0';
		if(x % 2 == 0)
		{
			std::swap(s[i], s[n-1]);
			puts(s);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
