#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int d1,int d2){
	return(d1>d2);
}
bool cmp1(int d1,int d2){
	return(d1%10<d2%10||(d1%10==d2%10&&d1<d2));		
}
int a[100],b[100],g[100],b1[100],a1[100];
int n,m,l1,l2,ans,d,pos,T;
int Get(int x,int y){
	int d=0;
	while(a[x]==b[y]&&x<=n&&y<=m) x++,y++,d++;
	return(d);
}
int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l1,&l2);
		n=m=ans=0;
		a[n]=b[m]=-100000000;
		for(int i=1;i<=l1;i++){
			scanf("%d",&a1[i]);
		}
		for(int i=1;i<=l2;i++){
			scanf("%d",&b1[i]);
		}
		sort(a1+1,a1+l1+1,cmp);sort(b1+1,b1+l1+1,cmp);
		for(int i=1;i<=l1;i++)
			if(a1[i]!=a[n]) a[++n]=a1[i];
		for(int i=1;i<=l2;i++)
			if(b1[i]!=b[m]) b[++m]=b1[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				d=Get(i,j);
				if(d>ans) ans=d,pos=i;
			}
		/*printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		printf("\n");
		for(int i=1;i<=m;i++) printf("%d ",b[i]);
		printf("\n");
		*/
		//printf("%d %d %d %d\n",n,m,ans,pos);
		for(int i=pos;i<=pos+ans-1;i++) printf("%d ",a[i]),g[i-pos+1]=a[i];
		if(ans) printf("\n");
		sort(g+1,g+ans+1,cmp1);
		for(int i=1;i<=ans;i++) printf("%d ",g[i]);
		if(ans) printf("\n");
		if(!ans) printf("NONE\n");
	}
	return 0;
}
