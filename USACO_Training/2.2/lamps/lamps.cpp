/*
LANG: C++
TASK: lamps
ID: jiangzh15
*/
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

int n,C,last[200];
int used[5],sta[200];
string res[200];
int Cnt=0;

void change(int *sta,int k)
{
	for(int i=1;i<=n;i++)
	{
		if(k==1)
		{
			sta[i]=1-sta[i];
		}
		else if(k==2)
		{
			if(i%2==1) sta[i]=1-sta[i];
		}
		else if(k==3)
		{
			if(i%2==0) sta[i]=1-sta[i];
		}
		else if(k==4)
		{
			if((i-1)%3==0) sta[i]=1-sta[i];
		}
	}
}

void dfs(int x,int left)
{
	if(x>4)
	{
		for(int i=1;i<=n;i++) sta[i]=1;
		for(int i=1;i<=4;i++)
			if(used[i]) change(sta,i);
		for(int i=1;i<=n;i++)
		{
			if(last[i]==0) continue;
			if(last[i]==1 && sta[i]==0) return;
			if(last[i]==-1 && sta[i]==1) return;
		}
		res[Cnt]="";
		for(int i=1;i<=n;i++)
			res[Cnt]+=(sta[i]+'0');
		Cnt++;
		return;
	}
	if(left>0)
	{
		used[x]=1;
		dfs(x+1,left-1);
	}
	used[x]=0;
	dfs(x+1,left);
}

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&C);
	int x;
	while(scanf("%d",&x) && x!=-1)
		last[x]=1;
	while(scanf("%d",&x) && x!=-1)
		last[x]=-1;
	dfs(1,C);
	std::sort(res,res+Cnt);
	for(int i=0;i<Cnt;i++)
		if(i==0 || res[i]!=res[i-1]) cout<<res[i]<<endl;
	if(!Cnt) printf("IMPOSSIBLE\n");
	return 0;
}
