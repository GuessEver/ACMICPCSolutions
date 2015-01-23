/*
LANG: C++
TASK: fracdec
ID: jiangzh15
*/
#include<cstdio>
#include<cstring>
#include<cmath>

int a,b;
int pos[100000+10];
int val[100000+10];

int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	scanf("%d%d",&a,&b);
	printf("%d.",a/b);
	int cnt=0,flag=0;
	int now=a%b;
	if(now==0)
	{
		printf("0\n");
		return 0;
	}
	while(1)
	{
		if(pos[now]) break;
		pos[now]=++cnt; val[pos[now]]=(now*=10)/b;
		if(now==0) {flag=1;break;}
		now=now%b;
	}
	int out=0,tmp=a/b;
	do{
		tmp/=10;
		out++;
	}while(tmp);
	out++;
	for(int i=1;i<pos[now];i++)
	{
		printf("%d",val[i]);
		if(++out%76==0) printf("\n");
	}
	if(flag) goto end;
	printf("(");
	if(++out%76==0) printf("\n");
	for(int i=pos[now];i<=cnt;i++)
	{
		printf("%d",val[i]);
		if(++out%76==0) printf("\n");
	}
	printf(")");
	if(++out%76==0) printf("\n");
	end:;
	printf("\n");
	return 0;
}
