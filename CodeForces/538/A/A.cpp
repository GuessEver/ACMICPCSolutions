#include <cstdio>
#include <cstring>

char s[1000], tmp[1000];
char t[] = "CODEFORCES";
int n;

bool solve()
{
	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
		{
			int len = 0;
			for(int i = 0; s[i]; i++)
			{
				if(i >= l && i <= r) continue;
				tmp[len++] = s[i];
			}
			tmp[len] = 0;
			if(!strcmp(tmp, t)) return 1;
		}
	return 0;
}

int main()
{
	scanf("%s", s); n = strlen(s);
	if(solve()) puts("YES"); else puts("NO");
	return 0;
}
