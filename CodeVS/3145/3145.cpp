#include<cstdio>

int n;

int f(int x)
{
	if(x==1) return 1;
	return 2*f(x-1)+1;
}

void solve(int x,int on,int under,char start,char mid,char tar)
{
	if(x==1)
	{
		printf("%d from %c to %c\n",on,start,tar);
		return;
	}
	solve(x-1,on,under-1,start,tar,mid);
	printf("%d from %c to %c\n",under,start,tar);
	solve(x-1,on,under-1,mid,start,tar);
}

int main()
{
	scanf("%d",&n);
	printf("%d\n",f(n));
	solve(n,1,n,'A','B','C');
	while(1);
	return 0;
}
