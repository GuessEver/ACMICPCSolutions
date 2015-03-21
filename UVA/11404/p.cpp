#include <cstdio>
#include <cstring>
#include <string>
using std::string;

char s[100];
int n, a[100];
string res;

void dfs(int x)
{
	if(x > n)
	{
		string s0 = "", s1 = "";
		for(int i = 1; i <= n; i++) if(a[i])
		{
			s0 = s0 + s[i];
			s1 = s[i] + s1;
		}
		if(s0 == s1 && (s0.length() > res.length() || (s0.length() == res.length() && s0 < res))) res = s0;
		return;
	}
	a[x] = 0; dfs(x+1);
	a[x] = 1; dfs(x+1);
}

int main()
{
	while(scanf("%s", s+1) == 1)
	{
		n = strlen(s+1);
		res = "";
		dfs(1);
		puts(res.c_str());
	}
	return 0;
}
