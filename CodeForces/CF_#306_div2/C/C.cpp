#include <cstdio>
#include <cstring>

char s[200];
int n;

int calc(int k, int j, int i)
{
	return (s[k] - '0') * 100 + (s[j] - '0') * 10 + (s[i] - '0');
}
int calc(int j, int i)
{
	return (s[j] - '0') * 10 + (s[i] - '0');
}

bool solve1()
{
	for(int i = 0; i < n; i++)
		if(s[i] == '8' || s[i] == '0')
		{
			printf("YES\n%c\n", s[i]);
			return 1;
		}
	return 0;
}
bool solve2()
{
	for(int i = n - 1; i >= 0; i--)
		for(int j = i - 1; j >= 0; j--)
		{
			int tmp = calc(j, i);
			if(tmp % 8 == 0)
			{
				printf("YES\n%d\n", tmp);
				return 1;
			}
		}
	return 0;
}
bool solve3()
{
	for(int i = n - 1; i >= 0; i--)
		for(int j = i - 1; j >= 0; j--)
			for(int k = j - 1; k >= 0; k--)
			{
				int tmp = calc(k, j, i);
				if(tmp % 8 == 0)
				{
					printf("YES\n%d\n", tmp);
					return 1;
				}
			}
	return 0;
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	if(!solve1() && !solve2() && !solve3()) puts("NO");
	return 0;
}
