#include<cstdio>
#include<cmath>
#include<cstring>

int n,m;
struct BigInt{
	int len,c[1000];
	BigInt(){memset(c,0,sizeof(c));len=1;}
	void Zero()
	{
		while(len>1 && c[len]==0) len--;
	}
	void Print()
	{
		printf("%d",c[len]);
		for(int i=len-1;i>=1;i--) printf("%04d",c[i]);
		printf("\n");
	}
	BigInt operator = (int a)
	{
		c[len=1]=a;
	}
	BigInt operator * (int a)
	{
		BigInt res;
		res.len=len+1;
		for(int i=1;i<=res.len;i++)
		{
			res.c[i]+=c[i]*a;
			res.c[i+1]+=res.c[i]/10000;
			res.c[i]%=10000;
		}
		res.Zero();
		return res;
	}
};

int main()
{
	scanf("%d%d",&m,&n);
	if(m==0) {printf("0\n");return 0;}
	if(n==0) {printf("1\n");return 0;}
	BigInt res;
	res=m;
	for(int i=1;i<n;i++)
	{
		res=res*m;
	}
	res.Print();
	return 0;
}
