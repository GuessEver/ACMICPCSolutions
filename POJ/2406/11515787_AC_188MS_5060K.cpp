#include<cstdio>
#include<cstring>

char s[1000000+10];
int len;
int next[1000000+10];

void getnext()
{
	memset(next,0,sizeof(next));
	next[0]=-1;
	int j=0,k=-1;
	while(j<len)
	{
		if(k==-1||s[j]==s[k]) next[++j]=++k;
		else k=next[k];
	}
}

int main()
{
	while(1)
	{
		memset(s,0,sizeof(s));
		scanf("%s",s);len=strlen(s);
		if(!strcmp(s,".")) break;
		getnext();
		//for(int i=0;i<=len;i++) printf("%d ",next[i]);puts("");
		if(len!=next[len] && len%(len-next[len])==0) printf("%d\n",len/(len-next[len]));
		else printf("1\n");
	}
	return 0;
}