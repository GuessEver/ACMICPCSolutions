#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 500100
using namespace std;
typedef struct{
	long long  y,next;
}node;
node g[maxn*10];
long long  a[maxn],q[maxn*5],v[maxn],d[maxn],size[maxn],succ[maxn],pre[maxn],gg[maxn],du[maxn],g2[maxn];
long long tot,head,tail,k,now,maxi,n,I,r,tot2,k1,k2,x,y,sum,ans,cnt,ans2,l,R,T,maxd,num;
void Add(int x,int y){
	//printf("gg %d %d\n",x,y);
	g[++tot].y=y;g[tot].next=a[x];a[x]=tot;
	g[++tot].y=x;g[tot].next=a[y];a[y]=tot;
}
long long Bfs(int k){
	int kk;
	q[head=tail=1]=k;
	memset(v,0,sizeof(v));
	memset(pre,0,sizeof(pre));
	memset(d,0,sizeof(d));
	v[k]=1;
	while(head>=tail){
		kk=q[tail++];
		for(int s=a[kk];s;s=g[s].next){
			now=g[s].y;
			if(!v[now]) d[now]=d[kk]+1,q[++head]=now,v[now]=1,pre[now]=kk;
		//	printf("tt %d %d %d\n",kk,now,d[now]);
		}
	}
	//printf("%d\n",k);
	//for(int i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
	maxi=1;maxd=0;
	memset(g2,0,sizeof(g2));
	for(int i=1;i<=n;i++)
		if(d[maxi]<d[i]) g2[g2[0]=1]=i,maxi=i;
			else if(d[maxi]==d[i]) g2[++g2[0]]=i; 
	for(int i=1;i<=g2[0];i++){
		num=0;
		//printf("ss %d %d\n",k,g2[i]);
		for(int j=g2[i];j;j=pre[j]) num+=du[j];
		if(num>maxd) maxd=num,maxi=i;
	}
	return(g2[maxi]);
}
int Dfs(int k){
	for(int s=a[k];s;s=g[s].next){
		int now=g[s].y;
		if(!v[now]){
			v[now]=1;
			size[k]+=Dfs(now);
		}
	}
	return(size[k]);
}
int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&n,&I,&R);
		memset(a,0,sizeof(a));
		memset(du,0,sizeof(du));
		tot=tot2=0;
		for(int i=1;i<n;i++) scanf("%lld%lld",&x,&y),Add(x,y),du[x]++,du[y]++;
		k1=Bfs(1);
		k2=Bfs(k1);
		//printf("%d %d\n",k1,k2);
		memset(succ,0,sizeof(succ));
		memset(v,0,sizeof(v));
		sum=ans=0;
		for(int i=k2;i!=k1;i=pre[i]) succ[pre[i]]=i;
		for(int i=k2;i;i=pre[i]) v[i]=1;
		for(int i=1;i<=n;i++) size[i]=1;
		for(int i=k2;i;i=pre[i]) size[i]=Dfs(i),sum+=size[i];
		for(int i=1;i<=n;i++) ans+=d[i];
		cnt=ans;
		l=0;
		for(int i=succ[k1];i;i=succ[i]){
			l+=size[pre[i]];r=sum-l;
			ans2=ans+(l-r);
			ans=ans2;
			if(ans2==cnt) gg[++tot2]=i;
				else if(ans2<cnt) gg[tot2=1]=i,cnt=ans2;
		}
		printf("%lld\n",cnt*I*I*R);
		sort(gg+1,gg+tot2+1);
		for(int i=1;i<=tot2;i++) printf("%lld ",gg[i]);
		if(T) printf("\n\n");
	}
	return 0;
}
