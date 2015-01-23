/*http://blog.csdn.net/jiangzh7
By Jiangzh*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=100+10;
const int M=10+3;

int n,m;
int map[N];
bool hash[1<<M];
int a[1<<M],Cnt;
LL f[N][60+10][60+10];
LL num[1<<M];
int all;

void PT(int s)
{
	int a[M];
	for(int i=m;i>=1;i--)
	{
		a[i]=s&1;s>>=1;
	}
	for(int i=1;i<=m;i++) printf("%d",a[i]);
	puts("");
}

void read()
{
	scanf("%d%d",&n,&m);
	char ss[M];
	for(int i=1;i<=n;i++)
	{
		scanf("\n%s",ss);
		for(int j=0;j<m;j++)
		if(ss[j]=='H') map[i]|=(1<<j);
	}
	all=(1<<m)-1;
}

LL count_1(int s)
{
	LL res=0;
	while(s)
	{
		res+=s&1;
		s>>=1;
	}
	return res;
}

void dfs(int S,int x)
{
	if(x>=m)
	{
		if(hash[S]) return;
		//printf("%d :",S);PT(S);
		hash[S]=true;
		a[++Cnt]=S;
		num[S]=count_1(S);
		return;
	}
	dfs((S<<1)&((1<<m)-1),x+1);
	if(!(S&1)) dfs(((S<<2)+1)&((1<<m)-1),x+1);
}

bool could(int s,int t,int k)
{
	if((s&t)!=0) return false;
	if((s&k)!=0) return false;
	if((t&k)!=0) return false;
	return true;
}

bool could2(int s,int t){return (s&t)==0;}

void work()
{
	dfs(0,0);
	for(int s=1;s<=Cnt;s++)
	{
		//printf("s : "); PT(a[s]);
		if(a[s]&map[1]) continue;
		f[1][s][1]=num[a[s]];
	}
	//puts("-----------------");
	for(int s=1;s<=Cnt;s++)
	{
		//printf("s : "); PT(a[s]);
		if(a[s]&map[2]) continue;
		for(int t=1;t<=Cnt;t++)
		if(could2(a[s],a[t]))
		{
			f[2][s][t]=num[a[s]]+num[a[t]];
		}
	}
	//puts("-----------------");
	for(int i=3;i<=n;i++)
	{
		//printf("%d : \n",i);
		for(int s=1;s<=Cnt;s++)
		{
			if(a[s]&map[i]) continue;
			//printf("s=%d : ",a[s]);PT(a[s]);
			for(int t=1;t<=Cnt;t++)
			{
				if(a[t]&map[i-1]) continue;
				//printf("t=%d : ",a[t]);PT(a[t]);
				for(int k=1;k<=Cnt;k++)
				{
					if(a[k]&map[i-2]) continue;
					//printf("k=%d : ",a[k]);PT(a[k]);
					if(could(a[s],a[t],a[k]))
					{
						f[i][s][t]=max(f[i][s][t],f[i-1][t][k]+num[a[s]]);
						//printf("%d\n",f[i][s][t]);
					}
				}
			}
		}
	}
	LL res=0;
	for(int s=1;s<=Cnt;s++)
	{
		for(int t=1;t<=Cnt;t++)
		{
			res=max(res,f[n][s][t]);
			//printf("%d ",f[n][s][t]);
		}
		//puts("");
	}
	cout<<res<<endl;
}

int main()
{
	read();
	work();
	return 0;
}

