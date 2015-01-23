/*
LANG: C++
TASK: prefix
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>

int cnt=0;
char t[200+10][10+10];
char s[200000+10];
int tlen[200+10],slen;
bool f[200000+10];

bool check(int i)
{
	for(int j=1;j<=cnt;j++)
	{
		if(i<tlen[j]) return 0;
		if(f[i-tlen[j]] && strncmp(s+i-tlen[j]+1,t[j],tlen[j])==0) return 1;
	}
	return 0;
}

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	while(scanf("%s",t[++cnt]) && strcmp(t[cnt],".")!=0)
	{
		tlen[cnt]=strlen(t[cnt]);
	}
	cnt--;
	s[0]='@';
	char tmp[100]={0};
	while(scanf("%s",tmp)==1) strcat(s,tmp);
	slen=strlen(s);
	//for(int i=1;i<=cnt;i++) printf("%s\n",t[i]);
	f[0]=1;
	for(int i=1;i<slen;i++)
		if(check(i)) f[i]=1;
	//for(int i=1;i<slen;i++)	printf("%d ",f[i]);
	for(int i=slen-1;i>=0;i--) if(f[i])
	{
		printf("%d\n",i);
		break;
	}
	return 0;
}
