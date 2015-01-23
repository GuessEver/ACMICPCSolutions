#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int N=1000+10;

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

int calc(int x,int time)
{
	if(f[x][time]!=-1) return f[x][time];
	if(!time) return f[x][time]=0;
	if(!L[x] && !R[x])
	{
		if(p[x]*5<=time-t[x]) return f[x][time]=p[x];
		else return f[x][time]=(time-t[x])/5;
	}
	f[x][time]=0;
	int tt=time-t[x];
	for(int i=0;i<=tt;i++)
	{
		int ll=calc(L[x],i);
		int rr=calc(R[x],tt-i);
		f[x][time]=max(f[x][time],ll+rr);
	}
	return f[x][time];
}

int main()
{
	freopen("1163.in","r",stdin);
	freopen("1163.out","w",stdout);
	scanf("%d",&Limit);
	build();
	//for(int i=1;i<=n;i++) printf("%d %d\n",L[i],R[i]);
	memset(f,-1,sizeof(f));
	printf("%d\n",calc(1,Limit));
	return 0;
}
