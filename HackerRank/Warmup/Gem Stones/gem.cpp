#include <cstdio>
#include <cstring>

int n;
char s[200];
int cnt[200]['z'+10];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		for(int j = 0; j < len; j++)
			cnt[i][s[j]]++;
	}
	int res = 0;
	for(char ch = 'a'; ch <= 'z'; ch++)
	{
		bool flag = 1;
		for(int i = 1; i <= n; i++)
			if(!cnt[i][ch]) flag = 0;
		res += flag;
	}
	printf("%d\n", res);
	return 0;
}
