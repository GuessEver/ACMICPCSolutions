#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100010
using namespace std;
typedef long long LL;
LL s1[maxn],d;
int m,n,t,cnt,p,l,r;
int main(){
	//freopen("test.in","r",stdin);
	while(cin>>n&&n){
		scanf("%d",&m);
		cnt=0;
		memset(s1,0,sizeof(s1));
		for(int i=1;i<=m;i++) scanf("%d%d%I64d",&l,&r,&d),s1[l]+=d,s1[r+1]-=d;
		scanf("%d",&t);
		for(int i=2;i<=n;i++) s1[i]+=s1[i-1];
		for(int i=2;i<=n;i++) s1[i]+=s1[i-1];
		for(int i=1;i<=t;i++){
			scanf("%I64d%d",&d,&p);
			if(s1[n]-s1[p-1]<d) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
