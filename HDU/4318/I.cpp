#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 51000
using namespace std;
typedef struct{
	int y,next;
	double d;
}node;
node g[maxn*50];
int q[maxn*10],v[maxn],a[maxn];
double d[maxn];
int n,x,k,s,t,po,tot;
void Add(int x,int y,double d){
	g[++tot].y=y;g[tot].d=1.0-d/100.0;g[tot].next=a[x];a[x]=tot;
}
void Spfa(){
	int head,tail,k,now;
	memset(d,0,sizeof(d));
	d[s]=po*1.0;q[head=tail=1]=s;v[s]=1;
	while(head>=tail){
		k=q[tail++];v[k]=0;
		for(int ss=a[k];ss;ss=g[ss].next){
			now=g[ss].y;
			if(d[now]<d[k]*g[ss].d){
				d[now]=d[k]*g[ss].d;
				if(!v[now]) q[++head]=now,v[now]=1;
			}
		}
	}
	//for(int i=1;i<=n;i++) printf("%d %lf\n",i,d[i]);
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n){
		int dd;
		tot=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d",&dd);
			for(int j=1;j<=dd;j++) scanf("%d%d",&x,&k),Add(i,x,(double)k);
		}
		scanf("%d%d%d",&s,&t,&po);
		Spfa();
		if(d[t]==0) printf("IMPOSSIBLE!\n");
			else printf("%.2lf\n",po*1.0-d[t]);
	}
	return(0);
}
