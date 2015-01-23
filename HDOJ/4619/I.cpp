#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 2010
using namespace std;
typedef struct{
	int y,next;
}node;
typedef struct{
	int x,y;
}node2;
node g[maxn*maxn*2];
node2 a[maxn],b[maxn];
int f[maxn],v[maxn],col[maxn],dfn[maxn],low[maxn],q[maxn],cc[maxn][2];
int n,m,cnt,tot,top,t,num;
void Add(int x,int y){
	//printf("%d %d\n",x,y);
	g[++tot].y=y;g[tot].next=f[x];f[x]=tot;
	g[++tot].y=x;g[tot].next=f[y];f[y]=tot;
}
void Tarjan(int k){
	int now;
	v[k]=1;
	dfn[k]=low[k]=++num;
	q[++top]=k;
	for(int s=f[k];s;s=g[s].next){
		now=g[s].y;
		if(!dfn[now]){
			Tarjan(now);
			low[k]=min(low[k],low[now]);
		}else if(v[now]) low[k]=min(low[k],dfn[now]);
	}
	if(low[k]==dfn[k]){
		t++;int y;
		do{
			y=q[top--];
			v[y]=0;
			col[y]=t;
		}while(y!=k);
	}
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n>>m&&(n||m)){
	tot=0;
	memset(f,0,sizeof(f));
	memset(v,0,sizeof(v));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(col,0,sizeof(col));
	memset(cc,0,sizeof(cc));
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++) scanf("%d%d",&b[i].x,&b[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[j].y<=a[i].y&&b[j].y+1>=a[i].y&&a[i].x<=b[j].x&&a[i].x+1>=b[j].x) Add(i,j+n);
	num=top=t=cnt=0;
	for(int i=1;i<=m+n;i++) if(!dfn[i]) Tarjan(i);
	//for(int i=1;i<=n+m;i++) printf("%d %d\n",i,col[i]);
	for(int i=1;i<=n;i++) cc[col[i]][1]++;
	for(int i=1;i<=m;i++) cc[col[i+n]][2]++;
	for(int i=1;i<=t;i++) cnt+=max(cc[i][1],cc[i][2]);
	printf("%d\n",cnt);
	}
	return(0);
}
