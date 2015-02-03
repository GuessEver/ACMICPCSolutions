#include <cstdio>
#include <cstring>

int n;
char s[110][110];
int cap['z'+10]['z'+10];
int in['z'+10];
int done['z'+10];
char ans[40];

bool build(char *p, char *t)
{
	int lenp = strlen(p);
	int lent = strlen(t);
	int len = lenp > lent ? lent : lenp;
	for(int i = 0; i < len; i++)
	{
		if(p[i] == t[i]) continue;
		if(!cap[p[i]][t[i]])
		{
			cap[p[i]][t[i]] = 1;
			in[t[i]]++;
		}
		return 0;
	}
	return lenp > lent;
}

bool solve()
{
	int cnt = 0;
	bool flag = 1;
	while(flag)
	{
		flag = 0;
		char res;
		for(char ch = 'a'; ch <= 'z'; ch++)
			if(!done[ch] && in[ch] == 0)
			{
				res = ch;
				flag = 1;
				break;
			}
		//putchar(res);
		done[res] = 1;
		ans[cnt++] = res;
		for(char ch = 'a'; ch <= 'z'; ch++)
			if(!done[ch] && cap[res][ch])
				in[ch]--;
	}
	return cnt >= 26;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);
	bool WRONG = 0;
	for(int i = 1; i < n; i++)
		WRONG |= build(s[i-1], s[i]);
	if(WRONG || !solve()) puts("Impossible");
	else{
		for(int i = 0; i < 26; i++) putchar(ans[i]);
		puts("");
	}
	return 0;
}
