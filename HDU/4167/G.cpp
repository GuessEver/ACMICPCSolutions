#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>
#include <map>
using std::string;
using std::map;

int n, maxlen;
char s[300], name[100];
char first[100], last[100];
map<string, int> cnt;

void PRINT(char *name, int len, int cc)
{
	if(cc >= 1 && cc <= 9)
	{
		if(len < maxlen) name[len] = cc + '0';
		else name[len-1] = cc + '0';
	}
	else if(cc >= 10)
	{
		int x = cc / 10, y = cc % 10;
		if(len + 2 <= maxlen) len += 2;
		else if(len + 1 <= maxlen) len += 1;
		name[len-2] = x + '0';
		name[len-1] = y + '0';
	}
	puts(name);
}

int main()
{
	int cas = 0;
	while(scanf("%d%d", &n, &maxlen) == 2 && (n || maxlen))
	{
		fgets(s, 300, stdin); 
		printf("Case %d\n", ++cas);
		cnt.clear();
		for(int i = 1; i <= n; i++)
		{
			fgets(s, 300, stdin);
			int tot = strlen(s);
			if(s[tot-1] == '\n') tot--;
			memset(name, 0, sizeof(name));
			int len = 0, pos = 0;
			while(s[pos] == ' ') pos++;
			name[len++] = tolower(s[pos]);
			pos = tot - 1;
			int pos2;
			while(s[pos] == ' ') pos--;
			pos2 = pos;
			while(s[pos] != ' ') pos--;
			for(int i = pos; i <= pos2; i++)
			{
				if(isalpha(s[i])) name[len++] = tolower(s[i]);
				if(len == maxlen) break;
			}
			//puts(name); puts("======");
			string tmp(name);
			PRINT(name, len, cnt[tmp]);
			cnt[tmp]++;
		}
	}
	return 0;
}
