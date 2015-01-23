#include<cstdio>
#include<cmath>
#define sqr(_) ((_)*(_))
int x[3],y[3],r[3];
int main()
{
	for(int i=1;i<=2;i++)
		scanf("%d%d%d",&x[i],&y[i],&r[i]);
	double res=sqrt((double)sqr(x[1]-x[2])+(double)sqr(y[1]-y[2]))*2.0;
	printf("%.6lf\n",res);
	return 0;
}
