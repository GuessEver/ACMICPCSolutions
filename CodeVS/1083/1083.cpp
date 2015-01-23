#include<cstdio>

int n;

int main()
{
	scanf("%d",&n);
	int i=1,sum=0;
	while(1)
	{
		sum+=i;
		if(sum>=n) {sum-=i;break;}
		i++;
	}
	n-=sum;
	if(i%2==0) printf("%d/%d",n,i-n+1);
	else printf("%d/%d",i-n+1,n);
	//while(1);
	return 0;
}
