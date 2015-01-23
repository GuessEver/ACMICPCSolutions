#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100010
using namespace std;
typedef long long LL;
LL cnt,a[maxn],b[maxn],c[maxn];
int hash[maxn];
int n;
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n&&n){
		for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
		memset(hash,0,sizeof(hash));
		for(int i=1;i<=n;i++){
			if(hash[a[i]]) b[i]=hash[a[i]];
				else b[i]=a[i];
			for(int j=1;j<=sqrt(a[i]);j++)
				if(a[i]%j==0) hash[j]=hash[a[i]/j]=a[i];
		}
		memset(hash,0,sizeof(hash));
		for(int i=n;i>=1;i--){
			if(hash[a[i]]) c[i]=hash[a[i]];
				else c[i]=a[i];
			for(int j=1;j<=sqrt(a[i]);j++)
				if(a[i]%j==0) hash[j]=hash[a[i]/j]=a[i];
		}
		cnt=0;
		//for(int i=1;i<=n;i++) printf("%d %d\n",b[i],c[i]);
		for(int i=1;i<=n;i++) cnt+=(b[i]*c[i]);
		printf("%I64d\n",cnt);
	}
}
