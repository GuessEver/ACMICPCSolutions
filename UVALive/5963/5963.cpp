#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define maxn 2000010
using namespace std;
int hash[maxn];
int a[maxn];
int T,n,d;
int flag;
typedef long long LL;
int main(){
	scanf("%d",&T);
	for(int kk=1;kk<=T;kk++){
		memset(hash,0,sizeof(hash));
		scanf("%d",&n);flag=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			d=a[i];
			if(d>=n){
				//printf("Case %d: no\n",kk);
				flag=0;
			}
			if(hash[d+1]+hash[n-d]==2){
				//printf("Case %d: no\n",kk);
				flag=0;
			}else{
				if(hash[d+1]==0) hash[d+1]=1;
					else hash[n-d]=1;
			}
		}
		if(flag) printf("Case %d: yes\n",kk);
			else printf("Case %d: no\n",kk);
	}	
}
