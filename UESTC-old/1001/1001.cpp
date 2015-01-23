#include<cstdio>
#include<cstring>
char s[100];

inline bool isnum(char ch)
{
	if(ch>='0' && ch<='9') return 1;
	return 0;
}
inline bool isop(char ch)
{
	if(ch=='+'||ch=='-') return 1;
	if(ch=='*'||ch=='/') return 1;
	return 0;
}

int solve()
{
	scanf("%s",s);
	int len=strlen(s);
	int i=0;
	if(!isnum(s[i=0])) return 0;
	i++;
	while(i<len)
	{
		while(s[i]=='.') i++;
		if(!isop(s[i])) return 0;
		i++;
		while(s[i]=='.') i++;
		if(!isnum(s[i])) return 0;
		i++;
	}
	return 1;
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		if(solve()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
