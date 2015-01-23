#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T,xa,ya,xb,yb,x,y;
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
		x=xb-xa;y=yb-ya;
		if(x<0&&y<0) x=-x,y=-y;
		if(x<=0&&y<=0){printf("Case %d: %d %d %d %d\n",i,0,-x,-y,0);continue;}
		if(x<=0&&y>=0){printf("Case %d: %d %d %d %d\n",i,0,0,y,-x);continue;}
		if(x>=0&&y<=0){printf("Case %d: %d %d %d %d\n",i,-y,x,0,0);continue;}
		if(x>=0&&y>=0){printf("Case %d: %d %d %d %d\n",i,0,x,y,0);continue;}
	}
}
