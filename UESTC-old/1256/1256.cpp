#include<cstdio>
#include<cstring>

char s[300];
int n;
bool three(char *s)
{
	int tmp=0;
	for(int i=0;i<n;i++)
		tmp+=s[i]-'0';
	return tmp%3==0;
}
bool eleven(char *s)
{
	int tmp=0,k=-1;
	for(int i=0;i<n;i++)
		tmp+=(s[i]-'0')*(k=-k);
	return tmp%11==0;
}

int main()
{
	freopen("1256.in","r",stdin);
	freopen("1256.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s); n=strlen(s);
		if(three(s)) printf("yes ");
		else printf("no ");
		if(eleven(s)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
