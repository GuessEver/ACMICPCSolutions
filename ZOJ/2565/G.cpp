#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define inf 200000000
using namespace std;
int a[200],t[30][30],f[200][30],ans[200][30];
int n,m,mini;
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n>>m){
		for(int i=1;i<n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++) scanf("%d",&t[i][j]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++) f[i][j]=inf;
		for(int i=1;i<=m;i++) f[n][i]=0;
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=m;j++) 
				for(int k=1;k<=m;k++){
					if(f[i][j]>f[i+1][k]+abs(a[i]-t[j][k])) ans[i][j]=k,f[i][j]=f[i+1][k]+abs(a[i]-t[j][k]);
				}
		}
		mini=1;
		for(int i=2;i<=m;i++)
			if(f[1][i]<f[1][mini]) mini=i;
		printf("%c",mini+'a'-1);
		for(int i=1;i<n;i++){
			printf("%c",ans[i][mini]+'a'-1);
			mini=ans[i][mini];
		}
		printf("\n");
	}
}
