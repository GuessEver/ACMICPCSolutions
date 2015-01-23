#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 30000100
using namespace std;
long long  ans[maxn],d;
int T,n;
int main(){	
	memset(ans,0,sizeof(ans));
	for(int i=1;i<maxn;i++)
		for(int j=i*2;j<maxn;j+=i)
			if(((j-i)^j)==i) ans[j]++;

	scanf("%d",&T);
	for(int i=1;i<maxn;i++) ans[i]+=ans[i-1];
	for(int kk=1;kk<=T;kk++){
		printf("Case %d: ",kk);
		scanf("%lld",&d),printf("%lld\n",ans[d]);
	}
}

	
