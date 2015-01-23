#include<cstdio>

int a,b;

int e_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int t=e_gcd(b,a%b,x,y);
	int tmp=x;x=y;y=tmp-a/b*y;
	return t;
}

int main()
{
	freopen("1200.in","r",stdin);
	freopen("1200.out","w",stdout);
	scanf("%d%d",&a,&b);
	int x,y;e_gcd(a,b,x,y);
	x=(x%b+b)%b;
	printf("%d\n",x);
	return 0;
}
