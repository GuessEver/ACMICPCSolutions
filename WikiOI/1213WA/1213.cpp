#include<cstdio>

int e_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int tmp=e_gcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return tmp;
}

int solve()
{
	int a,b,c,p,q,r,s;
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&p,&q,&r,&s);
	if(!a||!b||(!a&&!b&&c)) return 0;
	int x,y;
	int g=e_gcd(a,b,x,y);
	if(c%g!=0) return 0;
	int tmp=-c;tmp=tmp/g;
	x*=tmp;y*=tmp;
	//printf("%d %d\n",x,y);
	while(x<p) x+=b;
	while(x>q) x-=b;
	int res=0,oldx=x;
	while(x>=p)
	{
		y=(-a*x-c)/b;
		if(y>=r && y<=s) res++;
		x-=b;
	}
	x=oldx+b;
	while(x<=q)
	{
		y=(-a*x-c)/b;
		if(y>=r && y<=s) res++;
		x+=b;
	}
	return res;
}

int main()
{
	int t;scanf("%d",&t);
	while(t--) printf("%d\n",solve());
	return 0;
}