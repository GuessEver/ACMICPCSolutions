#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=15;

int n,m;
int map[N];
int a[1<<N],Cnt;
LL f[N][1<<N];

void PT(int s)//Debug
{
	int a[N];
	for(int i=m;i>=1;i--)
	{
		a[i]=s&1;
		s>>=1;
	}
	for(int i=1;i<=m;i++) printf("%d",a[i]);
	puts("");
}

void read()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		{
			int x;scanf("%d",&x);
			if(x) map[i]|=(1<<j);
		}
}

void dfs(int s,int x)//生成一行中所有可行排列
{
	if(x==m)
	{
		//PT(s);
		a[++Cnt]=s;
		return;
	}
	dfs(s<<1,x+1);
	if(!(s&1)) dfs((s<<1)+1,x+1);
}

bool could(int i,int s1,int s2)
{
	if((s1&map[i])!=s1) return false;
	if((s2&map[i-1])!=s2) return false;
	if((s1&s2)!=0) return false;
	return true;
}

void work()
{
	dfs(0,0);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int t=1,S=a[t];t<=Cnt;t++,S=a[t])
	for(int k=1,st=a[k];k<=Cnt;k++,st=a[k])
	{
		//printf("S:");PT(S);printf("st:");PT(st);
		if(could(i,S,st))
		{
			f[i][S]+=f[i-1][st];
			//printf("%d\n",f[i][S]);
		}
		//puts("");
	}
	LL res=0;
	for(int t=1,S=a[t];t<=Cnt;t++,S=a[t]) res+=f[n][S];
	cout<<res<<endl;
}

int main()
{
	//freopen("poj3254.in","r",stdin);
	//freopen("poj3254.out","w",stdout);
	read();
	work();
	//while(1);
	return 0;
}
