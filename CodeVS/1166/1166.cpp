#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100+10;

struct BigInt{
	int len,c[10];
	BigInt(){len=1;memset(c,0,sizeof(c));}
	void Print()
	{
		printf("%d",c[len]);
		for(int i=len-1;i>=1;i--) printf("%05d",c[i]);
		puts("");
	}
	void Zero()
	{
		while(!c[len]&&len>1) len--;
	}
};
int n,m;
int a[N];
BigInt f[N][N];

BigInt getmax(BigInt a,BigInt b)
{
	if(a.len<b.len) return b;
	if(a.len>b.len) return a;
	for(int i=a.len;i>=1;i--)
	{
		if(a.c[i]>b.c[i]) return a;
		if(a.c[i]<b.c[i]) return b;
	}
	return a;
}

BigInt P(BigInt a,BigInt b)
{
	BigInt res;
	res.len=max(a.len,b.len)+1;
	for(int i=1;i<=res.len;i++)
	{
		res.c[i]+=a.c[i]+b.c[i];
		res.c[i+1]+=res.c[i]/100000;
		res.c[i]%=100000;
	}
	res.Zero();
	return res;
}

BigInt P(BigInt a,int b)
{
	BigInt t; t.c[t.len=1]=b;
	BigInt res=P(a,t); res.Zero();
	return res;
}

BigInt work()
{
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int l=1;l<=m;l++)
	for(int i=1;i<=m-l+1;i++)
	{
		BigInt t=getmax(P(f[i+1][l-1],a[i]),P(f[i][l-1],a[i+l-1]));
		/*printf("l=%d i=%d\n",l,i);
		printf("f[i+1][l-1]=");f[i+1][l-1].Print();
		printf("f[i][l-1]=");f[i][l-1].Print();
		printf("a[i]=%d a[i+l-1]=%d\n",a[i],a[i+l-1]);
		printf("t=");t.Print();
		puts("");*/
		f[i][l]=getmax(f[i][l],P(t,t));
	}
	return f[1][m];
}

int main()
{
	scanf("%d%d",&n,&m);
	BigInt res;
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) f[i][j].len=1;
		BigInt t;t=work();
		res=P(res,t);
	}
	res.Print();
	return 0;
}
