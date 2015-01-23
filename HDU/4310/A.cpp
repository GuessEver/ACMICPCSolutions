#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 30
using namespace std;
typedef struct{
	long long d,p;
	double c;
}node;
long long tot[maxn],cnt;
node a[maxn];
int n;
bool cmp(node p1,node p2){
	return(p1.c<p2.c);
}
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n){
		for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].d,&a[i].p),a[i].c=(double)(a[i].p)/(double)(a[i].d);	
		sort(a+1,a+n+1,cmp);
		cnt=0;
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++) tot[i]=tot[i-1]+a[i].d;
		for(int i=1;i<=n;i++) cnt+=(tot[n]-tot[i-1])*a[i].p;
		printf("%lld\n",cnt);
	}
	return(0);
}
