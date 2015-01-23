#include<cstdio>

int n,L,v;

int main()
{
	freopen("1025.in","r",stdin);
	freopen("1025.out","w",stdout);
	while(scanf("%d%d%d",&n,&L,&v)==3&&n&&L&&v)
	{
		int sum=0,max=0;
		for(int i=1;i<=n;i++)
		{
			int pos;
			char s[10];scanf("%d%s%s",&pos,s,s);
			if(pos==0 && s[0]=='0') break;
			int leng;
			if(s[0]=='E') leng=L-pos;
			else leng=pos;
			if(leng>max) max=leng;
			sum+=leng;
		}
		printf("%.2lf %d.00\n",(double)max/v,sum);
	}
	return 0;
}
