#include<cstdio>
#include<cmath>
int main()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	if(fabs(a-b)<1e-8) puts("yes");
	else puts("no");
	//while(1);
	return 0;
}
