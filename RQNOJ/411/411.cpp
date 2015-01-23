#include<cstdio>
#include<cmath>
#define sqr(_) ((_)*(_))
int x[110],y[110],n;

int cross(int i,int j,int k)
{
	int x1=x[j]-x[i], y1=y[j]-y[i];
	int x2=x[k]-x[i], y2=y[k]-y[i];
	return x1*y2-x2*y1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	x[n+1]=x[1];y[n+1]=y[1];
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=cross(0,i,i+1);
	}
	printf("%d\n",res/2);
	return 0;
}
