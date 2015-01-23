#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 400100
#define maxm 3000000
#define inf 200000000
using namespace std;
typedef struct{
	int x,y,next;
}node;
node g[maxm],g2[maxm];
int a[maxn],dfn[maxn],low[maxn],q[maxn*10],v[maxn],d[maxn],col[maxn];
int n,m,tot,num,top,t,k1,k2,cnt,tot2;
void Add(int x,int y){
	g[++tot].y=y;g[tot].next=a[x];a[x]=tot;g[tot].x=x;
	g[++tot].y=x;g[tot].next=a[y];a[y]=tot;g[tot].x=y;
}
void Add2(int x,int y){
	cnt++;
	g2[++tot2].y=y;g2[tot2].next=a[x];a[x]=tot2;
	g2[++tot2].y=x;g2[tot2].next=a[y];a[y]=tot2;
}
void Dfs(int k,int pre){
	int now;
	v[k]=1;q[++top]=k;
	dfn[k]=low[k]=++num;
	for(int s=a[k];s;s=g[s].next){
		now=g[s].y;
		if(s==(pre^1)) continue;
		if(!dfn[now]){
			Dfs(now,s);
			low[k]=min(low[k],low[now]);
		}else if(v[now]) low[k]=min(low[k],dfn[now]);
	}	
	if(dfn[k]==low[k]){
		t++;int y;
		do{
			y=q[top--];
			v[y]=0;
			col[y]=t;
		}while(k!=y);
	}
}
int Bfs(int st){
	int maxi,head,tail,now,k;
	memset(v,0,sizeof(v));
	for(int i=1;i<=t;i++) d[i]=inf;
	v[st]=1;d[st]=0;q[head=tail=1]=st;
	while(head>=tail){
		k=q[tail++];
		for(int s=a[k];s;s=g2[s].next){
			now=g2[s].y;
			if(d[now]>d[k]+1){
				d[now]=d[k]+1;
				if(!v[now]) v[now]=1,q[++head]=now;
			}
		}
		v[k]=0;
	}
	maxi=st;
	for(int i=1;i<=t;i++) 
		if(d[i]>d[maxi]) maxi=i;
	return(maxi);
}
int main(){
	int k1,k2,x,y;
	//freopen("test.in","r",stdin);
	while(cin>>n>>m&&n){
		tot=1;
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),Add(x,y);
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(v,0,sizeof(v));
		memset(col,0,sizeof(col));
		top=t=num=0;
		for(int i=1;i<=n;i++) if(!dfn[i]) Dfs(i,-1);
		memset(a,0,sizeof(a));
		cnt=tot2=0;
		for(int i=1;i<=tot;i+=2)
			if(col[g[i].x]!=col[g[i].y]) Add2(col[g[i].x],col[g[i].y]);
		k1=Bfs(1);
		k2=Bfs(k1);
		//for(int i=1;i<=n;i++) printf("%d %d\n",i,col[i]);
		//printf("%d %d\n",cnt,d[k2]);
		printf("%d\n",cnt-d[k2]);
	}
	return(0);
}

