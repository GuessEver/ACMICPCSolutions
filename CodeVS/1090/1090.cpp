#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=30+10;
int vis[N][N],f[N][N];
string ss[N][N];
const string number[]=
{"0","1","2","3","4","5","6","7","8","9","10",
"11","12","13","14","15","16","17","18","19","20","21","22","23","24","25",
"26","27","28","29","30","31","32","33","34","35","36","37","38","39","40"};
int n;
int a[N],score[N];
string order="";

LL dfs(int l,int r,string &ll)
{
	if(l==r) {ll=number[l];return score[l];}
	if(l>r) return 1;
	if(vis[l][r]) {ll=ss[l][r];return f[l][r];}
	vis[l][r]=true;
	LL res=0;
	LL left=1,right=1;
	for(int x=l;x<=r;x++)
	{
		string lans="",rans="";
		left=dfs(l,x-1,lans);
		right=dfs(x+1,r,rans);
		if(res<left*right+score[x])
		{
            f[l][r]=res=left*right+score[x];
			ss[l][r]=ll=number[x]+" "+lans+" "+rans;
		}
	}
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&score[i]);
	LL res=dfs(1,n,order);
	cout<<res<<endl;
	for(int i=0;i<order.length();i++)
	{
		if(order[i]==' '&&i>0&&order[i-1]==' ') continue;
		else if(order[i]==' '&&i>0&&order[i-1]!=' ') cout<<' ';
		else cout<<order[i];
	}
	return 0;
}
