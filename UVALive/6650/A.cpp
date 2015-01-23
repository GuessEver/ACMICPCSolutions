#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int l,w,h,maxh,maxv,n;
int main(){
//	freopen("test.in","r",stdin);
	while(cin>>n&&n){
		maxh=0;maxv=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&l,&w,&h);
			if(h>maxh){
				maxh=h;maxv=l*w*h;
			}else if(h==maxh) maxv=max(maxv,l*w*h);
		}
		printf("%d\n",maxv);
	}
}
