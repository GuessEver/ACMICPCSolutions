#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1e6
using namespace std;
typedef long long LL;
const LL p=1000000007;
LL a[1000100];
int t,d;
int main(){
	a[1]=1;a[2]=1;a[3]=3;a[4]=11;
	//int maxn=100;
	for(int i=5;i<=maxn;i++){
		a[i]=((a[i-1]*i-a[i-3]*(i-3))%p+p)%p;
		//printf("%d %d\n",i,a[i]);
		//if(a[i]<0) printf("s\n");
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&d);
		printf("Case %d: %lld\n",i,a[d]);
		//if(i<t) printf("\n");
	}
}
