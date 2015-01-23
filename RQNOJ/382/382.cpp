#include<cstdio>
#include<cstring>

char a[100000+10],s[100000+10];
int lena,lens;
int next[100000+10];
int res,ans[100000+10];

void getnext()
{
	memset(next,0,sizeof(next));
	next[0]=-1;
	int j=0,k=-1;
	while(j<lena)
	{
		if(k==-1||a[j]==a[k]) next[++j]=++k;
		else k=next[k];
	}
}

void kmp()
{
	getnext();
	int i=0,j=0;
	while(i<lens)
	{
		if(j==-1||a[j]==s[i]) i++,j++;
		else j=next[j];
		if(j==lena) ans[res++]=i-lena;
	}
}

int main()
{
	scanf("%s\n%s",a,s);
	lena=strlen(a);lens=strlen(s);
	kmp();
	if(res)
	{
		printf("%d\n",res);
		for(int i=0;i<res;i++) printf("%d\n",ans[i]+1);
	}
	else printf("There must be something wrong.");
	return 0;
}

