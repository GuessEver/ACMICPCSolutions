#include<cstdio>

bool h[10000+10];
int l,n,x,y,sum;

int main()
{
	scanf("%d%d",&l,&n);
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		for(j=x;j<=y;j++)h[j]=true;
	}
	for(i=0;i<=l;i++)    
		if(!h[i]) sum++;
	printf("%d",sum);
	return 0;
}
