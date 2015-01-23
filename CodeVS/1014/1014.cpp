#include<cstdio>

int n,v;
bool f[20000+10];

int main()
{
	scanf("%d%d",&v,&n);
	f[0]=true;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		for(int j=v;j>=x;j--) if(f[j-x]) f[j]=true;
	}
	int m=0;
	for(int j=v;j>=0;j--)
	if(f[j])
	{
		m=j;
		break;
	}
	printf("%d\n",v-m);
	//while(1);
	return 0;
}
