#include<cstdio>

int n,x,sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		sum+=x;
	}
	printf("%d",sum);
	return 0;
}
