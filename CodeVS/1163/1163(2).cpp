#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int N=1000+10;
const int maxp=120;

int Limit;
int n,L[N],R[N];
int t[N],p[N];
int f[N][N];

int build()
{
	n++; scanf("%d%d",&t[n],&p[n]);
	t[n]*=2;
	int now=n;
	if(p[now]==0)
	{
		L[now]=build();
		R[now]=build();
	}
	return now;
}

void calc(int x)
{
	if(!x) return;
	if(!L[x] && !R[x])
	{
		f[x][0]=0;
		for(int i=1;i<=p[x];i++)
			f[x][i]=i*5+t[x];
		return;
	}
	calc(L[x]); calc(R[x]);
	for(int i=0;i<=maxp;i++)
		for(int k=0;k<=i;k++)
			f[x][i]=min(f[x][i],f[L[x]][k]+f[R[x]][i-k]+t[x]);
}

int main()
{
	freopen("1163.in","r",stdin);
	freopen("1163.out","w",stdout);
	scanf("%d",&Limit);
	build();
	//for(int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
	//memset(f,0x3f,sizeof(f));
	for(int i=1;i<=maxp;i++) 
		for(int j=1;j<=maxp;j++)
			f[i][j]=0x3f3f3f3f;
	calc(1);
	for(int i=maxp;i>=1;i--)
		if(f[1][i]<=Limit) {printf("%d\n",i);return 0;}
	return 0;
}
