#include <cstdio>
#include <cstring>

char s[100];
int len;
int n = 0;
int ans = 0, total = 0;

void dfs(int i, int pos)
{
	if(i == len)
	{
		total++;
		if(pos == n) ans++;
		return;
	}
	if(s[i] == '+' || s[i] == '?') dfs(i+1, pos+1);
	if(s[i] == '-' || s[i] == '?') dfs(i+1, pos-1);
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	for(int i = 0; i < len; i++)
	{
		if(s[i] == '+') n++;
		else n--;
	}
	scanf("%s", s);
	len = strlen(s);
	dfs(0, 0);
	printf("%.12lf\n", 1.0 * ans / total);
	return 0;
}
