#include<cstdio>

int calc(int x)
{
	if(x==1) return 1;
	int res=0;
	for(int i=1;i<=x/2;i++)
	{
		res+=calc(i);
	}
	res++;
	return res;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",calc(n));
	while(1);
	return 0;
}
