#include<cstdio>

int main()
{
	int a;double b;
	scanf("%d%lf",&a,&b);
	a=(int)(a*b/10.0+0.5);
	a=(a+5)/10*10;
	printf("%d\n",a);
	return 0;
}
