#include <cstdio>
#include <cstring>

char s[100100];
int cnt['z'+10] = {0};

bool solve()
{
	bool flag = 0;
	for(char i = 'a'; i <= 'z'; i++)
	{
		if(cnt[i] & 1)
		{
			if(!flag) flag = 1;
			else return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		cnt[s[i]]++;
	if(solve()) puts("YES");
	else puts("NO");
	return 0;
}
