#include<cstdio>

int gcd(int a,int b){return (b)?gcd(b,a%b):a;}
inline int lcm(int a,int b){ return a/gcd(a,b)*b; }

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int res=0;
	int a,b;
	for(a=x;a<=y;a++)
	{
		//printf("%d ",a);
		//getchar();
		if(x%a==0)
		{
			b=x/a*y;
			if(gcd(a,b)==x&&lcm(a,b)==y) res++;
		}
		else if(y%a==0)
		{
			b=y/a*x;
			if(gcd(a,b)==x&&lcm(a,b)==y) res++;
		}
	}
	printf("%d\n",res);
	//while(1);
	return 0;
}
