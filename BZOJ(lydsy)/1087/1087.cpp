/**************************************************************
    Problem: 1087
    User: jiangzh
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:9280 kb
****************************************************************/
 
#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=10;
const int ALL=(1<<N);
int n,k;
int a[ALL],m;
LL f[N][N*N][ALL];
int num[ALL];
 
void write(int s,int deep)
{
	if(deep==n) {printf("%d",s);return;}
	write(s>>1,deep+1);
	printf("%d",s&1);
}
 
int cc(int s)
{
	int res=0;
	while(s)
	{
		res+=s&1;
		s>>=1;
	}
	return res;
}
 
void dfs(int S,int x)
{
	if(x==n)
	{
		//write(S,0);puts("");
		a[++m]=S;num[S]=cc(S);
		//printf("%d\n",num[S]);
		return;
	}
	dfs(S<<1,x+1);
	if((S&1)==0) dfs((S<<1)+1,x+1);
}
 
bool can(int s,int st)
{
	int S=s;
	S=S|(s<<1)|(s>>1);
	S=S&((1<<n)-1);
	if((S&st)==0) return true;
	else return false;
}
 
int main()
{
	//freopen("king.in","r",stdin);
	//freopen("king.out","w",stdout);
	scanf("%d%d",&n,&k);
	dfs(0,0);

	for(int l=1,S=a[l];l<=m;l++,S=a[l]) f[1][num[S]][S]++;
 
	for(int i=2;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int l=1,S=a[l];l<=m;l++,S=a[l])
				for(int r=1,st=a[r];r<=m;r++,st=a[r])
					if(can(S,st)&&j-num[S]-num[st]>=0)
						f[i][j][S]+=f[i-1][j-num[S]][st];
	LL res=0;
	for(int l=1,S=a[l];l<=m;l++,S=a[l]) res+=f[n][k][S];
	cout<<res;
	return 0;
}
