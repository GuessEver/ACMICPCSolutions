#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 101000
using namespace std;
typedef struct{
	int x,y,d;
}node;
int n,k,T,f1,f2,d;
long long sum,cnt;
node g[maxn];
int f[maxn],v[maxn],t[maxn];
bool cmp(node p1,node p2){
	return(p1.d>p2.d);
}
int Find(int k){
	int x=k;
	while(x!=f[x]) x=f[x];
	return(x);
}
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		cnt=sum=0;
		for(int i=1;i<n;i++) scanf("%d%d%I64d",&g[i].x,&g[i].y,&g[i].d),sum+=g[i].d;
		sort(g+1,g+n,cmp);
		memset(v,0,sizeof(v));
		memset(t,0,sizeof(t));
		for(int i=1;i<=k;i++) scanf("%d",&d),v[d]=1,t[d]=1;
		for(int i=0;i<=n;i++) f[i]=i;
		for(int i=1;i<n;i++){
			f1=Find(g[i].x);f2=Find(g[i].y);
			//printf("%d %d %d %d\n",g[i].x,f1,g[i].y,f2);
			if(f1==f2){
				cnt+=g[i].d;
				continue;
			}
			if(t[f1]+t[f2]==2) continue;
				else if(t[f1]+t[f2]==1) t[f1]=t[f2]=1,f[f1]=f2,cnt+=g[i].d;
					else f[f1]=f2,cnt+=g[i].d;
			//printf("%d %d\n",g[i].d,cnt);
		}
		//for(int i=0;i<n;i++) printf("%d %d\n",i,Find(i));
		printf("%I64d\n",sum-cnt);
	}
	return(0);
}
