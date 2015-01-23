#include<cstdio>
#include<algorithm>
using namespace std;

double f(double x,double y,int k)
{
	//printf("x=%.2lf  y=%.2lf  k=%d\n",x,y,k);
	if(x<y) swap(x,y);
	if(k==1) return x/y;
	double res=1e10;
	for(int i=1;i<k;i++)
	{
		double a=max(f(x/(double)k*i,y,i),f(x/(double)k*(k-i),y,k-i));
		double b=max(f(x,y/(double)k*i,i),f(x,y/(double)k*(k-i),k-i));
		res=min(res,min(a,b));
	}
	return res;
}

int main()
{
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int x,y,k;
	scanf("%d%d%d",&x,&y,&k);
	printf("%.6lf\n",f(x,y,k));
	return 0;
}
