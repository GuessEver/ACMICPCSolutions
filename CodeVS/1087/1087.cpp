#include<cstdio>
#include<cmath>
#include<cstring>
const int number=100000;

int p;
long long a[400],b[400];

void mul(int n)
{
	if(!n) return;
	mul(n/2);
	for(int i=1;i<=100;i++)
		for(int j=1;j<=100;j++)
		{
			if(n%2==0) b[i+j-1]+=a[i]*a[j];
			else b[i+j-1]+=a[i]*a[j]*2;
		}
	for(int i=1;i<=100;i++)
	{
		a[i]=b[i]%number;
		b[i+1]+=b[i]/number;
	}
	memset(b,0,sizeof(b));
}

int main()
{
	scanf("%d",&p);
	printf("%d\n",(int)(log(2)/log(10)*p)+1);
	a[1]=1;
	mul(p);
	a[1]--;
	int cnt=0;
	for(int i=100;i>=1;i--)
	{
		printf("%05lld",a[i]);
		if(++cnt==10) {cnt=0;printf("\n");}
	}
	return 0;
}
