#include <cstdio>
#include <cstring>
#include <string>

int n;
char s[300000 + 10];
char t[300000 + 10];

int calc(int i)
{
	int x = s[(i+1)%n] - s[i];
	return x < 0 ? x + 8 : x;
}

bool check(int p, int j)
{
	int cnt = 0;
	while(cnt < n)
	{
		if(t[p] < t[j]) return 0;
		else if(t[p] > t[j]) return 1;
		p++; j++; cnt++;
		p %= n; j %= n;
	}
	return 0;
}

int main()
{
	while(scanf("%s", s) == 1)
	{
		n = strlen(s);
		int mind = 10;
		for(int i = 0; i < n; i++)
		{
			int now = calc(i);
			if(now < mind) mind = now;
			char ch = now + '0';
			t[i] = ch;
		}
		//puts(t); puts("----");
		int pos = 0;
		for(int i = 0; i < n; i++)
		{
			if(t[i] - '0' != mind) continue;
			if(check(pos, i)) pos = i;
			while(t[i] - '0' == mind) i++;
			i--;
		}
		for(int i = pos, cnt = 0; cnt < n; cnt++, i = (i + 1) % n)
			putchar(t[i]);
		puts("");
	}
	return 0;
}
