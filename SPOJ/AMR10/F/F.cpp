#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	//freopen("test.in","r",stdin);
	int n,a,d,T,ans=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&d);
		ans=(a+(n-1)*d+a)*n/2;
		printf("%d\n",ans);
	}
}
