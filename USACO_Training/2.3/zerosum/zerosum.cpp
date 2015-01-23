/*
LANG: C++
TASK: zerosum
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
char op[]={' ','+','-'};
int n;
int a[100];

void dosth(int *a)
{
	char s[100]={'1',0};
	char tmp[100]={'1',0};
	for(int i=1;i<n;i++)
	{
		s[strlen(s)]=op[a[i]];
		if(a[i]!=0) tmp[strlen(tmp)]=op[a[i]];
		s[strlen(s)]=(i+1+'0');
		tmp[strlen(tmp)]=(i+1+'0');
	}
	//strcpy(tmp,"1+2-3+4-5");
	int res=0; sscanf(tmp,"%d",&res);
	char op; int x,len=0;
	if(res==0 || res==1) len=1;
	else len+=(int)(log10((double)(abs(res)))+0.9999);
	while(sscanf(tmp+len,"%d",&x)==1)
	{
		res+=x;
		len+=(int)(log10((double)(abs(x)))+0.9999)+1;
		if(len==strlen(tmp)) break;
	}
	//printf("%s    %s\n",s,tmp);
	//printf("%d\n",res);
	if(res==0) printf("%s\n",s);
}

void dfs(int x)
{
	if(x==n)
	{
		dosth(a);
		return;
	}
	for(int k=0;k<3;k++)
	{
		a[x]=k;
		dfs(x+1);
	}
}

int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	dfs(1);
	return 0;
}
