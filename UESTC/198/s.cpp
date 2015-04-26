#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned __int64
#define ll __int64
//#define ull unsigned long long
//#define ll long long
#define son1 New(p.xl,xm,p.yl,ym),(rt<<2)-2
#define son2 New(p.xl,xm,min(ym+1,p.yr),p.yr),(rt<<2)-1
#define son3 New(min(xm+1,p.xr),p.xr,p.yl,ym),rt<<2
#define son4 New(min(xm+1,p.xr),p.xr,min(ym+1,p.yr),p.yr),rt<<2|1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define middle (l+r)>>1
#define MOD 1000000007
#define esp (1e-8)
const int INF=0x3F3F3F3F;
const double DINF=10000.00;
//const double pi=acos(-1.0);
const int N=25010,M=150010;
int n,m,tot;
struct node{
	char op[2];
	int p,x[6],y[6];
}q[N];
int X[M],len[M<<2];
double vol[M<<2],ld[M<<2],rd[M<<2],tmp;

int bs(int key,int size,int A[]){
	int l=0,r=size-1,mid;
	while(l<=r){
		mid=middle;
		if(key>A[mid]) l=mid+1;
		else if(key<A[mid]) r=mid-1;
		else return mid;
	}return -1;
}

void init(){
	int i,j;
	scanf("%d",&n);
	for(i=m=0;i<n;i++){
		scanf("%s",q[i].op);
		if(q[i].op[0]=='Q'){
			scanf("%d%d",&q[i].x[0],&q[i].y[0]);
			X[m++]=q[i].x[0],X[m++]=q[i].y[0];
		}else{
			scanf("%d",&q[i].p);
			for(j=0;j<q[i].p;j++){
				scanf("%d%d",&q[i].x[j],&q[i].y[j]);
				X[m++]=q[i].x[j];
			}q[i].x[j]=q[i].x[0],q[i].y[j]=q[i].y[0];
		}
	}
	sort(X,X+m);
	for(i=tot=1;i<m;i++) if(X[i]!=X[i-1]) X[tot++]=X[i];
}

void Build(int l,int r,int rt){
	len[rt]=X[r+1]-X[l];
	vol[rt]=ld[rt]=rd[rt]=0;
	if(l==r) return;
	int mid=middle;
	Build(lson),Build(rson);
}

double Cal(double lc,double rc,int a,int b){return (rc*a+lc*b)/(a+b);}

void Func(int rt,double lc,double rc){
	ld[rt]+=lc,rd[rt]+=rc;
	vol[rt]+=(lc+rc)/2*len[rt];
}

void PushUp(int rt){vol[rt]=vol[rt<<1]+vol[rt<<1|1];}

void PushDown(int rt){
	if(ld[rt]==0 && rd[rt]==0) return;
	int ls=rt<<1,rs=ls|1;
	tmp=Cal(ld[rt],rd[rt],len[ls],len[rs]);
	Func(ls,ld[rt],tmp),Func(rs,tmp,rd[rt]);
	ld[rt]=rd[rt]=0;
}

void Update(int l,int r,int rt,int L,int R,double lc,double rc){
	if(L<=l && r<=R){
		Func(rt,Cal(lc,rc,X[l]-X[L],X[R+1]-X[l]),Cal(lc,rc,X[r+1]-X[L],X[R+1]-X[r+1]));
		return;
	}
	PushDown(rt);
	int mid=middle;
	if(L<=mid) Update(lson,L,R,lc,rc);
	if(mid<R) Update(rson,L,R,lc,rc);
	PushUp(rt);
}

double Query(int l,int r,int rt,int L,int R){
	if(L<=l && r<=R) return vol[rt];
	PushDown(rt);
	int mid=middle;
	double ret=0;
	if(L<=mid) ret+=Query(lson,L,R);
	if(mid<R) ret+=Query(rson,L,R);
	return ret;
}

void sof(){
	Build(0,tot,1);
	int i,j,l,r;
	for(i=0;i<n;i++){
		if(q[i].op[0]=='Q'){
			l=bs(q[i].x[0],tot,X),r=bs(q[i].y[0],tot,X);
			printf("%.3lf\n",l<r? Query(0,tot,1,l,r-1):0);
		}else for(j=0;j<q[i].p;j++){
			l=bs(q[i].x[j],tot,X),r=bs(q[i].x[j+1],tot,X);
			if(l<r) Update(0,tot,1,l,r-1,-q[i].y[j],-q[i].y[j+1]);
			else Update(0,tot,1,r,l-1,q[i].y[j+1],q[i].y[j]);
		}
	}
}

int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int T,cas;scanf("%d",&T);for(cas=1;cas<=T;cas++){
		init();
		sof();
	}
	return 0;
}
