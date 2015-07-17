#include <cstdio>
#include <string>
#include <algorithm>
using std::string;

int n;
string s[110];
char str[110];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		s[i] = str;
	}
	std::sort(s + 1, s + n + 1);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(s[j] != s[i]) break;
			res = std::max(res, j - i + 1);
		}
	}
	printf("%d\n", res);
	return 0;
}
