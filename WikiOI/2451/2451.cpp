#include<cstdio>
#include<iostream>
using namespace std;
const int N=10;
typedef long long LL;

int n,k;
LL f[N][N*N][1<<N];
int a[1<<N],m=0,num[1<<N];

void pri(int s,int deep)
{
	if(deep==n) {printf("%d",s);return;}
	pri(s>>1,deep+1);
	printf("%d",s&1);
}

void dfs(int x,int s)
{
	if(x==n)
	{
		//pri(s,0);puts("");
		a[++m]=s;
		for(int S=s;S;S=S>>1) num[s]+=(S&1);
		//printf("%d\n",num[s]);
		return;
	}
	dfs(x+1,s<<1);
	if((s&1)==0) dfs(x+1,(s<<1)+1);
}

bool can(int s,int st)
{
	int S=s;
	S=(S|(s<<1))|(s>>1);
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		int ss=S&1,tt=st&1;
		S>>=1;st>>=1;
		if(ss&tt) {flag=false;break;}
	}
	if(flag) return true;
	else return false;
}

int main()
{
	scanf("%d%d",&n,&k);
	
	dfs(0,0);
	for(int idx=1,S=a[idx];idx<=m;idx++,S=a[idx]) f[1][num[S]][S]++;
	//for(int idx=1,S=a[idx];idx<=m;idx++,S=a[idx]) printf("%d ",f[1][1][S]);
	for(int i=2;i<=n;i++)
	for(int j=0;j<=k;j++)
	for(int idx=1,S=a[idx];idx<=m;idx++,S=a[idx])
	for(int ix=1,st=a[ix];ix<=m;ix++,st=a[ix])
	{
		//printf("%d %d ",i,j);pri(S,0);putchar(' ');pri(st,0);puts("");
		if(can(S,st)&&j-num[S]-num[st]>=0)
		{
			f[i][j][S]+=f[i-1][j-num[S]][st];
			//printf("%d\n",f[i][j][S]);
		}
	}
	//for(int idx=1,S=a[idx];idx<=m;idx++,S=a[idx]) printf("%d ",f[n][k][S]);
	LL res=0;
	for(int idx=1,S=a[idx];idx<=m;idx++,S=a[idx]) res+=f[n][k][S];
	cout<<res<<endl;
	return 0;
}
