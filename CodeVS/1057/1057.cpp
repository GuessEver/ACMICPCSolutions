#include<cstdio>

int save=0,now=0;
int a[20];

int main()
{
	int n=12;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		now+=300;
		now-=a[i];
		if(now<0) {printf("%d",-i);return 0;}
		save+=now/100*100;
		now%=100;
	}
	double res=now+(double)save*1.2;
	printf("%.0lf",res);
	//while(1);
	return 0;
}
