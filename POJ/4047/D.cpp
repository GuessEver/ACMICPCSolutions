#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>

#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
int a[200200],b[200200],d[200200],c[801000],l[801000],r[8010000],f[801000],p,x,y,n,m,k;
 void build(int x,int ll,int rr){
	l[x]=ll;r[x]=rr;if (l[x]==r[x]) { c[x]=a[l[x]];f[x]=0;/*cout<<x<<" "<<l[x]<<" "<<r[x]<<" "<<c[x]<<endl;*/return ;}
	int mid=(ll+rr)>>1;build(x<<1,ll,mid);build((x<<1)+1,mid+1,rr);
	c[x]=max(c[x<<1],c[(x<<1)+1]);f[x]=0;
	//cout<<x<<" "<<l[x]<<" "<<r[x]<<" "<<c[x]<<endl;
}
 void push(int x,int v){
	if (l[x]==r[x]) return ;
	if (f[x]==0) return ;
	c[x<<1]+=v;f[x<<1]+=v;
	c[(x<<1)+1]+=v;f[(x<<1)+1]+=v;
	f[x]=0;
}
 void change(int x,int v,int ll,int rr){
	//cout<<x<<" "<<ll<<" "<<rr<<endl;
	if (ll<=l[x] && r[x]<=rr) { c[x]+=v;f[x]+=v;return ;}
	push(x,f[x]);
	int mid=(l[x]+r[x])>>1;
	if (ll<=mid) change(x<<1,v,ll,rr);
	if (rr>mid) change((x<<1)+1,v,ll,rr);
	c[x]=max(c[x<<1],c[(x<<1)+1]);
}
int ask(int x,int ll,int rr){
	//cout<<x<<" "<<ll<<" "<<rr<<endl;
	if (ll<=l[x] && r[x]<=rr) return c[x];
	int tmp=-0x3f3f3f3f;push(x,f[x]);
	int mid=(l[x]+r[x])>>1;
	if (ll<=mid) tmp=ask(x<<1,ll,rr);
	if (mid<rr) tmp=max(tmp,ask((x<<1)+1,ll,rr));
	c[x]=max(c[x<<1],c[(x<<1)+1]); 
	return tmp;
}
int main(){
	int ttt,tmp;
	scanf("%d",&ttt);
	while (ttt--){
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n) scanf("%d",&b[i]);
		rep(i,1,n) d[i]=d[i-1]+b[i];
		rep(i,1,n) a[i]=d[i+k-1]-d[i-1];
		//rep(i,1,n) cout<<b[i]<<" ";cout<<endl;
	//	rep(i,1,n) cout<<d[i]<<" ";cout<<endl;
	//	rep(i,1,n) cout<<a[i]<<" ";cout<<endl;
		clr(c,0);build(1,1,n-k+1);
		rep(i,1,m){
			scanf("%d%d%d",&p,&x,&y);
			if (p==0) {change(1,y-b[x],max(1,x-k+1),min(x,n-k+1));b[x]=y;}
			if (p==1) {
				change(1,b[y]-b[x],max(1,x-k+1),min(x,n-k+1));
				change(1,b[x]-b[y],max(1,y-k+1),min(y,n-k+1));
				tmp=b[x];b[x]=b[y];b[y]=tmp;
			}
			if (p==2) printf("%d\n",ask(1,x,max(1,y-k+1)));;
		}
	}
	return 0;
}

